#include "AI.h"
int main(int argc, char const *argv[])
{
    int i=0,i2=0,i3=0, d=0;
    Uint32 dt,t_prev;
    Struct_robot ROBOT;
    ROBOT2 robot,robot1;
    point point;
    Struct_robotAtt ROBOTA;
    SDL_Event event;
    SDL_Surface *ecran = NULL,*map = NULL,*minimap = NULL,*RectangleRobot;
    SDL_Rect  positionmap,positionminimap,PosRectangleRobot;
    miniMAP MP;
    positionmap.x=0;
    positionmap.y=100;
positionminimap.x=200;
    positionminimap.y=110;

    PosRectangleRobot.x=500;
    PosRectangleRobot.y=250;





         
    map=IMG_Load("map.png");
        minimap=IMG_Load("minimap.png");

    RectangleRobot=IMG_Load("Rectangle.png");
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(900, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF| SDL_RESIZABLE);
    //initialiser
    initialiser (&ROBOT);
    initialiser2(&robot);
     initialiserpoint (&point);
     initialiserattack(&ROBOTA);
    while (ROBOT.A)
    {
        t_prev = SDL_GetTicks();
        d=AI(&robot,&ROBOT,ecran,dt);
        SDL_PollEvent(&event);
        {
        if (event.type==SDL_QUIT)
            (ROBOT.A)=0;
        }
         SDL_BlitSurface(RectangleRobot,NULL, ecran,&PosRectangleRobot);
    
          //i2=robot2mouvemant(&robot,ecran,i2,robot.Posrobot);
        
        
        //deplacer robot
        i=Mouvemant(&ROBOT,ecran,i);
        
        
        Mouvemantpoint(&point,ecran,&MP);

        
        //afficher
        affichage(&ROBOT,&ROBOTA,ecran,i,map,positionmap,minimap,positionminimap,d);
        Testecran(&ROBOT);
        affichage2(&robot,ecran,i2,RectangleRobot,PosRectangleRobot,&point);
        SDL_Flip(ecran);
        dt = SDL_GetTicks()-t_prev;
            if (1000/FPS>dt)
            SDL_Delay(1000/FPS-dt);
        
    }

   liberation(&ROBOT);
   liberation2(&robot);
   SDL_FreeSurface(map);
      SDL_FreeSurface(minimap);
            SDL_FreeSurface(point.point);


   SDL_Quit();


}
