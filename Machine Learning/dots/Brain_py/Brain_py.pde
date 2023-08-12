Population test;
AllObstacles obs;
PFont f;

PVector goal = new PVector(540,10);

void setup(){
  size(1080, 900);
  test = new Population(2000);
  obs = new AllObstacles();
  
}
    
void draw(){
  background(255);
  fill(255,0,0);
  ellipse(goal.x, goal.y, 10, 10);
  f = createFont("Arial",16,true);
  textFont(f, 16);
  fill(255, 125, 75);
  text("Gen: " + test.gen, 10 ,height-10);
  text("Min Steps: " + test.minSteps, 10 ,height-30);
  obs.show();
  if (mousePressed){
    goal.x = mouseX;
    goal.y = mouseY;
    fill(255,0,0);
    ellipse(goal.x, goal.y, 10, 10);
    test.minSteps = 400;
    test.stepsBefore = 400;
  }
  if (test.allDead()){
    test.calcFitness();  
    test.selection();
    test.mutate();
    
  }else{
    test.update();
    test.show();
  }
  
}
