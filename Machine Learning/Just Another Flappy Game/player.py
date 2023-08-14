import pygame
import os

startX : float  = 200
startY : float = 200

class Player:
    def __init__(self) -> None:
        self.cordX = startX
        self.cordY = startY
        self.velocity = 10
        self.isJumping = False
        self.isDead = False
        self.gravityVal = 0.7
        self.cordY_change = 0
        self.max_cordY_change = 12
        self.score = 0
        self.width, self.height = 60,60

    def show(self,i) -> pygame.image:
        player = pygame.image.load(os.path.join("images", f"frame-{i}.png"))
        player = pygame.transform.scale(player,(60,60))
        return player
    
    def showScore(self) -> pygame.image:
        scoreCounts = []
        for i in range(len(str(self.score))):
            scoreCounts.append(pygame.image.load(os.path.join("images", f"{str(self.score)[i]}.png")))
        return scoreCounts


    def resetStats(self) -> None:
        self.cordX = startX
        self.cordY = startY
        self.isDead = False
        self.score = 0

    def jump(self, gameStart) -> None:
        if gameStart and self.cordY + self.cordY_change < 620:
            self.cordY += min(self.cordY_change, self.max_cordY_change)
            self.cordY_change += self.gravityVal
        if self.cordY > 580:
            self.isDead = True
            self.cordY = 580

    # def closestPipe(self, pipes) -> float:
    #     dist = 2000
    #     for p in pipes:
    #         if p.cordX < dist:
    #             dist = p.cordX
    #     if dist < 200:
    #         dist = 2000
    #         print("dupa")
    #         self.score += 1
            
    #     return dist




    
                

  

