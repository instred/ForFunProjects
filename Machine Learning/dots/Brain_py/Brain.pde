float mutationRate = 0;

class Brain{
  int step = 0;
  PVector[] directions;
  
  Brain(int size){
    directions = new PVector[size];
    randomize();
  }
        
    
  void randomize(){
    for (int i = 0; i< directions.length; i++){
      
      float randomAngle = random(2*PI);
      directions[i] = PVector.fromAngle(randomAngle);
    }       
  }
  
  Brain clone(){
    Brain clone = new Brain(directions.length);
    for (int i=0; i<directions.length; i++){
      clone.directions[i] = directions[i].copy(); 
    }
    return clone;
  }
  
  void mutate(int stuck){
    if (stuck > 7){
      mutationRate = 0.15;
      
    }else{
      mutationRate = 0.01;
    }
    
    for (int i=0; i<directions.length; i++){
      float rand = random(1);
      if (rand < mutationRate){
        
        // set this to random directions
        float randomAngle = random(2*PI);
        directions[i] = PVector.fromAngle(randomAngle);
        
      }
    }
  }
}
        
