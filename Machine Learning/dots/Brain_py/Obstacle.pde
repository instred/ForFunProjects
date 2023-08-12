class Obstacle{
  
  PVector pos;
  PVector boundaries;
  Boolean inside = false;
  
  
  Obstacle(float x, float y, float wdth, float hgth){
    pos = new PVector(x, y);
    boundaries = new PVector(wdth, hgth);
  }
    
    
  void show(){
    fill(0,0,255);
    rect(pos.x,pos.y,boundaries.x,boundaries.y); 
    
  }
  
  Boolean test(float x, float y){
    if (x<(pos.x+boundaries.x) && y<(pos.y+boundaries.y) && x>pos.x && y>pos.y){
      return true; 
    }
    return false;
  }
    
    
    
}
