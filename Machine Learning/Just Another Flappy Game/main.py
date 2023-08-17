import pygame
from pygame.locals import *
import os
import player
import math
import sys
import pipe
import random

pygame.init()
pygame.font.init()

player = player.Player()
width : int = 800
height : int = 625
game_fps : int = 60
die_sound = pygame.mixer.Sound(os.path.join("audio", "die.wav"))
hit_sound = pygame.mixer.Sound(os.path.join("audio", "hit.ogg"))
point_sound = pygame.mixer.Sound(os.path.join("audio", "point.ogg"))
swoosh_sound = pygame.mixer.Sound(os.path.join("audio", "swoosh.ogg"))


clock = pygame.time.Clock()
window = pygame.display.set_mode((width,height))

pygame.display.set_caption("Just Another Flappy Game")

game_bg = pygame.image.load(os.path.join("images", "background.jpg"))
game_bg = pygame.transform.scale(game_bg,(width,height))
redColor = pygame.Color(255, 0, 0)



def gameOver() -> None:
    pygame.mixer.Sound.play(hit_sound)
    pygame.mixer.Sound.play(die_sound)
    gameover : bool = True
    while gameover:

        # add prettier Game Over sign to player 

        gameOverFont = pygame.font.Font('freesansbold.ttf', 50)
        gameOverSurf = gameOverFont.render('Game Over, press R to respawn', True, redColor)
        gameOverRect = gameOverSurf.get_rect()
        gameOverRect.midtop = (320, 10)
        window.blit(gameOverSurf, gameOverRect)
        pygame.display.flip()
        event = pygame.event.wait()
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == KEYDOWN:
            if event.key == K_r:
                player.resetStats()
                mainLoop(player)
                gameover = False

def showScore(scoreCounts) -> None:
    for i in range(len(scoreCounts)):
        window.blit(scoreCounts[i], (width/2-5+(i*20), 20))


def mainLoop(player) -> None:
    
    bgX : int = 0
    player_frame : int = 1
    run_game : bool = True
    gameStart : bool = False
    pipes = [pipe.Pipe(1000+ 300*i) for i in range(5)]

    while run_game:
        
        clock.tick(game_fps)
        window.fill((0,0,0))
        window.blit(game_bg,(bgX,0))
        window.blit(game_bg,(width+bgX+0.1,0))
        window.blit(player.show(math.floor(player_frame)), (player.cordX, player.cordY))
        showScore(player.showScore())
        if gameStart:
            for p in pipes:
                p.cordX -= 3
                window.blit(p.show(False), (p.cordX, p.cordY))
                window.blit(p.show(True), (p.cordX, p.cordY + p.height+200))
                if (p.checkCollision(False,player)) or (p.checkCollision(True,player)):
                    player.isDead = True
                if p.cordX < 200 and p.cordX > 196:
                    player.score += 1
                    pygame.mixer.Sound.play(point_sound)
                    
                if p.cordX < -60:
                    p.cordX = 1450

        
        # simple background looping + player frames looping
        # player flickers when new background appears need fix
        if (bgX < -width):
            window.blit(game_bg,(width+bgX,0))
            bgX=0
        # if width+bgX < 255:
        #     window.blit(player.show(math.floor(player_frame)), (player.cordX, player.cordY))
        
        bgX-=2
        if (player_frame >= 4.89):
            player_frame = 1
        player_frame+=0.1

        #add a death animation

        if player.isDead:
            gameOver()
            gameStart = False
            
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run_game = False
                sys.exit()
            # start the game on arrow up
            if event.type == KEYDOWN:
                if event.key == K_UP and not gameStart:
                    gameStart = True
                    player.cordY_change = -player.velocity
                    pygame.mixer.Sound.play(swoosh_sound)
                elif event.key == K_UP:
                    player.cordY_change = -player.velocity
                    pygame.mixer.Sound.play(swoosh_sound)
        player.jump(gameStart)
            
            

        pygame.display.update()


if __name__ == "__main__":
    mainLoop(player)