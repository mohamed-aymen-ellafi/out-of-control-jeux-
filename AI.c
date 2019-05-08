#include "robot.h"
/*void initialiserpoint (point *point)
{
    point->Pospoint.x=200;
    point->Pospoint.y=115;
    point->point=IMG_Load("point.png");
}*/

void initialiserattack(Struct_robotAtt *ROBOTA)
{
     ROBOTA->Posrobot.x=0;
     ROBOTA->Posrobot.y=420;
    ROBOTA->robotattack[0]= IMG_Load("a.png");
    ROBOTA->robotattack[1]= IMG_Load("b.png");
    ROBOTA->robotattack[2]= IMG_Load("c.png");
    ROBOTA->robotattack[3]= IMG_Load("d.png");
    ROBOTA->robotattack[4]= IMG_Load("e.png");
    ROBOTA->robotattack[5]= IMG_Load("f.png");
    ROBOTA->robotattack[6]= IMG_Load("g.png");
        
}

void initialiser(Struct_robot *ROBOT)
{
     ROBOT->Posrobot.x=0;
     ROBOT->Posrobot.y=420;
    ROBOT->robot[0]= IMG_Load("22.png");
    ROBOT->robot[1]= IMG_Load("33.png");
    ROBOT->robot[2]= IMG_Load("44.png");
    ROBOT->robot[3]= IMG_Load("55.png");
    ROBOT->robot[4]= IMG_Load("66.png");
    ROBOT->robot[5]= IMG_Load("77.png");
    ROBOT->robot[6]= IMG_Load("88.png");
    ROBOT->robot[7]= IMG_Load("99.png");
        
}


/*void initialiserminiMap (miniMAP *minimap)
{
    minimap->PosminiMap.x=400;
    minimap->PosminiMap.y=100;
    minimap->PosRectminiMap.x=0;
    minimap->PosRectminiMap.y=0;
    minimap->minimap=IMG_Load("minimap.png");
}

*/




/*void affichageMINIMAP(miniMAP *minimap)
{
  SDL_BlitSurface(minimap->minimap,NULL,ecran,&minimap->PosminiMap);
}*/

void affichage(Struct_robot *ROBOT,Struct_robotAtt *ROBOTA,SDL_Surface *ecran,int i,int distance)
{
      
    SDL_Delay(100);         
    if (distance>100)
    SDL_BlitSurface(ROBOT->robot[i],NULL, ecran,&ROBOT->Posrobot);
    if (distance<100)
            SDL_BlitSurface(ROBOTA->robotattack[i],NULL, ecran,&ROBOT->Posrobot);

     //SDL_Flip(ecran);
}

/*void affichage2(ROBOT2 *robot,SDL_Surface *ecran,int i,SDL_Surface *RectangleRobot,SDL_Rect PosRectangleRobot,point *point)
{      
    SDL_Delay(1);
    SDL_BlitSurface(RectangleRobot,NULL,ecran,&PosRectangleRobot);
        SDL_Delay(1);

        SDL_BlitSurface(point->point,NULL,ecran,&point->Pospoint); 
 
    SDL_BlitSurface(robot->robot[i],NULL, ecran,&robot->Posrobot);
     //SDL_Flip(ecran);
}*/


/*void Mouvemantpoint(point *point,SDL_Surface *ecran,miniMAP *MP)
{
        point->Pospoint.y=125;
                SDL_Delay(1);

        point->Pospoint.x+=1;
        if (point->Pospoint.x==MP->PosRectminiMap.x+535)
                   point->Pospoint.x=200;
 
       
}*/








void liberation(Struct_robot *ROBOT,Struct_robotAtt *att)
{
    int i=0;
    for (i=0;i<=9;i++)
    SDL_FreeSurface(ROBOT->robot[i]);
      for (i=0;i<=7;i++)
    SDL_FreeSurface(att->robotattack[i]);
}

