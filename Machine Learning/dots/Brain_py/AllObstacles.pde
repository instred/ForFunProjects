class AllObstacles{
  Obstacle[] obs;
  
  AllObstacles(){
    int x = 0;
    float y = 1.5;
    int wdth = 600;
    obs = new Obstacle[12];
    for (int i = 0; i < 8; i+=2){
      obs[i] = new Obstacle(x, y*100, wdth, 10); 
      obs[i+1] = new Obstacle(wdth+200, y*100, width-wdth-200, 10);
      y += 2;
      wdth -= 200;
    }
    obs[8] = new Obstacle(0,0,width,10);
    obs[9] = new Obstacle(0,0,10,height);
    obs[10] = new Obstacle(0,height-10,width,10);
    obs[11] = new Obstacle(width-10,0,10,height);

  }
  
  void show(){
    for (int i = 0; i<obs.length; i++){
      obs[i].show();
    }
    
  }
  
  
}
