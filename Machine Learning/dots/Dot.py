import Brain

class Dot:
    Vec position
    PVector velocity
    PVector acceleration
    
    def __init__(self) -> None:
        brain = Brain(400)
        
        position = new PVector(width/2, height/2)
        velocity = new PVector(0, 0)
        acceleration = new PVector(0, 0)
        
    def show() -> None:
        fill(0)
        ellipse(position.x, position.y, 4, 4)
    
    
    def move() -> None:
        if len(brain.directions) > brain.step:
            acceleration = brain.directions[brain.step]
            brain_step++
        
        velocity.add(acceleration)
        position.add(velocity)
    
