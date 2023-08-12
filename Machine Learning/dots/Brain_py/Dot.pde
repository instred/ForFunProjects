class Dot  {
  PVector position;
  PVector velocity;
  PVector acceleration;
  Brain brain;
  Boolean dead = false;
  Boolean reachedGoal = false;
  Boolean isBest = false;
  float fitness;
  AllObstacles obstacles;
  Boolean hit = false;
  
  Dot(){
    brain = new Brain(1000);
    obstacles = new AllObstacles();
    
    position = new PVector(200, height-25);
    velocity = new PVector(0, 0);
    acceleration = new PVector(0, 0);
  }
      
  void show(){
    if (isBest){
      fill(0, 255, 0);
      ellipse(position.x, position.y, 8, 8);
    }else{
      fill(0);
      ellipse(position.x, position.y, 4, 4);
    }
    
  }
  
  
  void move(){
    if (brain.directions.length > brain.step){
      acceleration = brain.directions[brain.step];
      brain.step++;
    }
    else{
      dead = true; 
    }
    velocity.add(acceleration);
    velocity.limit(6);
    position.add(velocity);
  }
  
  void update(){
    if (!dead && !reachedGoal){
      move();
      if (position.x < 2 || position.y < 2 || position.y > height-2 || position.x > width-2){
        dead = true;
      }
      else if(dist(position.x, position.y, goal.x, goal.y) < 2){
          reachedGoal = true;
      }
      for (int i=0; i<obstacles.obs.length; i++){
        if (obstacles.obs[i].test(position.x, position.y)){
          dead = true;
          hit = true;
        }
      }
    }
  }
  
  void calcFitness(){
    if (reachedGoal){
        fitness = 1.0/16.0 +10000.0/(float)(brain.step*brain.step);
    }
    else{
      
      float distGoal = dist(position.x, position.y, goal.x, goal.y);
      if (hit){
        distGoal += 400; 
      }
      fitness = 1.0/(distGoal*distGoal);
      
    }
    
    
    
  }
  
  Dot giveBaby(){
    Dot baby = new Dot();
    baby.brain = brain.clone();
    
    
    return baby;
  }
}

    
