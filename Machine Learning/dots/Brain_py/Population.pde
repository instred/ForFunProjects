class Population{
  Dot[] dots;
  int fitnessSum;
  int gen = 1;
  int bestDot = 0;
  int minSteps = 400;
  int stuck = 1;
  int stepsBefore = minSteps;
  
  Population(int size){
    dots = new Dot[size];
    for (int i=0; i<size; i++){
      dots[i] = new Dot(); 
    }
  }
  
  void show(){
    for (int i=1; i<dots.length; i++){
      dots[i].show();
    }
    dots[0].show();
  }
  
  void update(){
    for (int i=0; i<dots.length; i++){
      if (dots[i].brain.step > minSteps){
        dots[i].dead = true; 
      }else{
        dots[i].update();
      }
    }
  }
  
  void calcFitness(){
    for (int i=0; i<dots.length; i++){
      dots[i].calcFitness();
    }
  }
  
  Boolean allDead(){
    for (int i=0; i<dots.length; i++){
      if (!dots[i].dead && !dots[i].reachedGoal){
        return false; 
      }
    }
    return true;
  }
  
  void selection(){
    Dot[] newDots = new Dot[dots.length];
    bestDot();
    calcFitnessSum();
    
    newDots[0] = dots[bestDot].giveBaby();
    newDots[0].isBest = true;
    for (int i = 1; i < newDots.length; i++){
       //select dot parent based on their fitness score
      Dot parent = selectParent();
      newDots[i] = parent.giveBaby();
      
    }
    dots = newDots.clone();
    gen ++;
    if (minSteps == stepsBefore){
      stuck++;  
    }else{
      stuck = 0;
    }
    
    
    
    
  }
  
  void calcFitnessSum(){
    fitnessSum = 0;    
    for (int i=0; i<dots.length; i++){
      fitnessSum += dots[i].fitness ;
      }
    }
    
   Dot selectParent(){
     float rand = random(fitnessSum);
     float runningSum = 0;
     
     for (int i=0; i<dots.length; i++){
       runningSum += dots[i].fitness;
       if (runningSum > rand){
         return dots[i];
       }
     }
     return null;
   }
   
   void mutate(){
     for (int i=1; i<dots.length; i++){
       dots[i].brain.mutate(stuck);
     }

   }
   
   void bestDot(){
     float max = 0;
     int maxIdx = 0;
     for (int i=0; i<dots.length;i++){
       if(dots[i].fitness > max){
         max = dots[i].fitness;
         maxIdx = i;
         
       }
     }
     bestDot = maxIdx;
     
     if (dots[bestDot].reachedGoal){
       stepsBefore = minSteps;
       minSteps = dots[bestDot].brain.step;
       
     }
     
   }
  
   
  
}
