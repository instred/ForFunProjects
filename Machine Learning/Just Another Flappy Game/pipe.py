import pygame
import random
import os

class Pipe:
    def __init__(self, x) -> None:
        self.cordX = x
        self.cordY = random.randint(-350, 0)
        self.height = 400
        self.width = 80

    def show(self,isDown) -> pygame.image:
        pipe = pygame.image.load(os.path.join("images", "pipe-red.png"))
        pipe = pygame.transform.scale(pipe,(self.width,self.height))
        if not isDown:
            pipe = pygame.transform.flip(pipe, False, True)
            
        return pipe

    def checkCollision(self, isDown, player) -> bool:
        if not isDown:
             return (player.cordY < self.cordY + self.height-1 and player.cordX > self.cordX-player.width+3
                     and player.cordX < self.cordX + self.width-10)
        else:
            return (player.cordY > self.cordY + self.height+205 - player.height and player.cordX > self.cordX-player.width+3
                     and player.cordX < self.cordX + self.width-10)
    
    def checkPoint(self, window, player) -> bool:
        pygame.draw.line(window, (255,0,0), (self.cordX+self.width/2, self.cordY+self.height),
                          (self.cordX + self.width/2, self.cordY+self.height+200))
        return (player.cordX > self.cordX + self.width/2)
                