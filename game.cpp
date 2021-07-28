#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;
int PORT= 4444;
int matrix[19][19];
bool visited[19][19];
bool InQueue=false;
int sp1=0,sp2=0;
bool t=false;
bool p=false;
bool quit=false;
bool aux=false;
int spcount=0;
class Menu
{    public:
        Menu(float width,float height)
        {
                if(!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/samanata.ttf"))
                {
                  
                }

           menu[0].setFont(font);
           menu[0].setFillColor(sf::Color::Red);
           menu[0].setString("Play");
           menu[0].setPosition(width/2.2,height/4*1);
           menu[1].setFont(font);
           menu[1].setFillColor(sf::Color::White);
           menu[1].setString("Options");
           menu[1].setPosition(width/2.2,height/4*2);
           menu[2].setFont(font);
           menu[2].setFillColor(sf::Color::White);
           menu[2].setString("Exit");
           menu[2].setPosition(width/2.2,height/4*3);
           itmIndex=0;
        }
        void reIninit()
        {
           
           menu[0].setFillColor(sf::Color::Red);
           
           menu[1].setFillColor(sf::Color::White);
          
           menu[2].setFillColor(sf::Color::White);
          
           itmIndex=0; 
        }
        int getKey()
        {
                return itmIndex;
        }
        void draw(sf::RenderWindow &wnd)
        {
                for(int i=0;i<3;i++)
                {
                        wnd.draw(menu[i]);
                }
        }
        void MoveUp()
        {
                if(itmIndex-1>=0)
                {
                        menu[itmIndex].setFillColor(sf::Color::White);
                        itmIndex--;
                        menu[itmIndex].setFillColor(sf::Color::Red);
                }
        }
        void MoveDown()
        {
                 if(itmIndex+1<=2)
                {
                        menu[itmIndex].setFillColor(sf::Color::White);
                        itmIndex++;
                        menu[itmIndex].setFillColor(sf::Color::Red);
                }
        }
    int itmIndex;
    sf::Font font;
    sf::Text menu[3];
};
class FinalScreen
{
        public:
        FinalScreen(float width,float height)
        {
                if(!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/samanata.ttf"))
                {
                  
                }
           menu[0].setCharacterSize(30);
           menu[0].setFont(font);
           menu[0].setFillColor(sf::Color:: Blue);
           menu[0].setString("The game has ended,press enter to see the table!");
           menu[0].setPosition(width/2.6,height/3);
           itmIndex=0;
        }
        int getKey()
        {
                return itmIndex;
        }
        void reIninit()
        {
          
           menu[0].setFillColor(sf::Color::Blue);
           
           itmIndex=1; 
        }
        void draw(sf::RenderWindow &wnd)
        {
                for(int i=0;i<2;i++)
                {
                        wnd.draw(menu[i]);
                }
        }
        

    int itmIndex;
    sf::Font font;
    sf::Text menu[2];
};
class Options
{
public:
        Options(float width,float height)
        {
                if(!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/samanata.ttf"))
                {
                  
                }

           menu[0].setFont(font);
           menu[0].setFillColor(sf::Color::Red);
           menu[0].setString("9x9 Grid");
           menu[0].setPosition(width/2.5,height/4*1);
           menu[1].setFont(font);
           menu[1].setFillColor(sf::Color::White);
           menu[1].setString("13x13 Grid");
           menu[1].setPosition(width/2.5,height/4*1.5);
           menu[2].setFont(font);
           menu[2].setFillColor(sf::Color::White);
           menu[2].setString("19x19 Grid");
           menu[2].setPosition(width/2.5,height/4*2);
           menu[3].setFont(font);
           menu[3].setFillColor(sf::Color::White);
           menu[3].setString("Back");
           menu[3].setPosition(width/2.5,height/4*2.5);
           itmIndex=0;
        }
        int getKey()
        {
                return itmIndex;
        }
        void reIninit()
        {
          
           menu[0].setFillColor(sf::Color::Red);
          
           menu[1].setFillColor(sf::Color::White);
          
           menu[2].setFillColor(sf::Color::White);

           menu[3].setFillColor(sf::Color::White);
           
           itmIndex=0; 
        }
        void draw(sf::RenderWindow &wnd)
        {
                for(int i=0;i<4;i++)
                {
                        wnd.draw(menu[i]);
                }
        }
        void MoveUp()
        {
                if(itmIndex-1>=0)
                {
                        menu[itmIndex].setFillColor(sf::Color::White);
                        itmIndex--;
                        menu[itmIndex].setFillColor(sf::Color::Red);
                }
        }
        void MoveDown()
        {
                 if(itmIndex+1<=3)
                {
                        menu[itmIndex].setFillColor(sf::Color::White);
                        itmIndex++;
                        menu[itmIndex].setFillColor(sf::Color::Red);
                }
        }
    int itmIndex;
    sf::Font font;
    sf::Text menu[4];
};


class Pquit
{
         public:
        Pquit(float width,float height,bool p)
        {
                if(!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/samanata.ttf"))
                {
                  
                }

           if(p){
           menu[0].setFont(font);
           menu[0].setFillColor(sf::Color::Red);
           menu[0].setString("You have quit the game,press enter to continue...");
           menu[0].setPosition(width/8,height/3);
           itmIndex=0;}
           else
           {
           menu[0].setFont(font);
           menu[0].setFillColor(sf::Color::Red);
           menu[0].setString("Your oponent has quit the game,press enter to continue...");
           menu[0].setPosition(width/14,height/3);
           itmIndex=0;
           }
        }
        int getKey()
        {
                return itmIndex;
        }
        void reIninit()
        {
          
           menu[0].setFillColor(sf::Color::Red);
          
           
           itmIndex=0; 
        }
        void draw(sf::RenderWindow &wnd)
        {
                for(int i=0;i<1;i++)
                {
                        wnd.draw(menu[i]);
                }
        }
    int itmIndex;
    sf::Font font;
    sf::Text menu[2];
};
class Play
{
   public:
        Play(float width,float height)
        {
                if(!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/samanata.ttf"))
                {
                  
                }

           menu[0].setFont(font);
           menu[0].setFillColor(sf::Color::Red);
           menu[0].setString("Play Online");
           menu[0].setPosition(width/2.5,height/4*1);
           menu[1].setFont(font);
           menu[1].setFillColor(sf::Color::White);
           menu[1].setString("Play Offline");
           menu[1].setPosition(width/2.5,height/4*2);
           menu[2].setFont(font);
           menu[2].setFillColor(sf::Color::White);
           menu[2].setString("Back");
           menu[2].setPosition(width/2.5,height/4*3);
          
           itmIndex=0;
        }
        int getKey()
        {
                return itmIndex;
        }
        void reIninit()
        {
          
           menu[0].setFillColor(sf::Color::Red);
          
           menu[1].setFillColor(sf::Color::White);
          
           menu[2].setFillColor(sf::Color::White);
           
           itmIndex=0; 
        }
        void draw(sf::RenderWindow &wnd)
        {
                for(int i=0;i<3;i++)
                {
                        wnd.draw(menu[i]);
                }
        }
        void MoveUp()
        {
                if(itmIndex-1>=0)
                {
                        menu[itmIndex].setFillColor(sf::Color::White);
                        itmIndex--;
                        menu[itmIndex].setFillColor(sf::Color::Red);
                }
        }
        void MoveDown()
        {
                 if(itmIndex+1<=2)
                {
                        menu[itmIndex].setFillColor(sf::Color::White);
                        itmIndex++;
                        menu[itmIndex].setFillColor(sf::Color::Red);
                }
        }

    int itmIndex;
    sf::Font font;
    sf::Text menu[3];
};
class FindingMatch
{
    public:
        FindingMatch(float width,float height)
        {
                if(!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/samanata.ttf"))
                {
                  
                }
           menu[0].setCharacterSize(30);
           menu[0].setFont(font);
           menu[0].setFillColor(sf::Color:: Blue);
           menu[0].setString("Waiting for players...");
           menu[0].setPosition(width/2.6,height/3);
           itmIndex=0;
        }
        int getKey()
        {
                return itmIndex;
        }
        void reIninit()
        {
          
           menu[0].setFillColor(sf::Color::Blue);
           
           itmIndex=1; 
        }
        void draw(sf::RenderWindow &wnd)
        {
                for(int i=0;i<2;i++)
                {
                        wnd.draw(menu[i]);
                }
        }
        

    int itmIndex;
    sf::Font font;
    sf::Text menu[2];
};
int cell_size=50;
int dimension=13;
bool isWindow=true;
void draw_board(sf::RenderWindow &window)
{
           float half_cell=1.0*cell_size/2;
                     for(int y=0;y<dimension;y++) {
                             sf::Vertex hline[]= {
                                     sf::Vertex(sf::Vector2f(half_cell,half_cell+y*cell_size)),
                                     sf::Vertex(sf::Vector2f(cell_size*dimension-half_cell,half_cell+y*cell_size))
                                                 };
                             hline[0].color=sf::Color::Black;
                             hline[1].color=sf::Color::Black;
                             window.draw(hline,2,sf::Lines);
                     }
                     for(int x=0;x<dimension;x++)
                     {
                             sf::Vertex vline[]={
                                     sf::Vertex(sf::Vector2f(half_cell+x*cell_size,half_cell)),
                                     sf::Vertex(sf::Vector2f(half_cell+x*cell_size,cell_size*dimension-half_cell))
                             };
                             vline[0].color=sf::Color::Black;
                             vline[1].color=sf::Color::Black;
                             window.draw(vline,2,sf::Lines);
                     }
         if(dimension>9){
          float startpR=half_cell/5;
          sf::CircleShape circle(startpR);
          circle.setFillColor(sf::Color::Black);
          circle.setRadius(5.f);
          for(int y=0;y<3;y++)
           for(int x=0;x<3;x++)
            {circle.setPosition(half_cell+(3+6*x)*cell_size-startpR,half_cell+(3+6*y)*cell_size-startpR);
             if((circle.getPosition().x<cell_size*dimension)&&(circle.getPosition().y<cell_size*dimension))
             window.draw(circle);
            }
         }

}
void draw_score(sf::RenderWindow &window,bool p,bool skip)
{
          sf::Font font;
          sf::Text txt[4];
          if(!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/samanata.ttf"))
                {
                  
                }
        if(p){
        txt[0].setCharacterSize(15);
        txt[0].setFont(font);
        txt[0].setFillColor(sf::Color::Black);
        txt[0].setString("You are player 1 (BLACK):");
        txt[0].setPosition(cell_size*dimension,100);
        window.draw(txt[0]);

        txt[1].setCharacterSize(15);
        txt[1].setFont(font);
        txt[1].setFillColor(sf::Color::Black);
        char s[30]="Your captures: ";
        char sc[20];
        sprintf(sc,"%d",sp1);
        strcat(s,sc);
        txt[1].setString(s);
        txt[1].setPosition(cell_size*dimension,150);
        window.draw(txt[1]);

        txt[2].setCharacterSize(15);
        txt[2].setFont(font);
        txt[2].setFillColor(sf::Color::Black);
        char s1[30]="Opponent's captures: ";
        char sc1[20];
        sprintf(sc1,"%d",sp2);
       
        
        strcat(s1,sc1);
        txt[2].setString(s1);
        txt[2].setPosition(cell_size*dimension,200);
        window.draw(txt[2]);
        }
        else
        {
        txt[0].setCharacterSize(15);
        txt[0].setFont(font);
        txt[0].setFillColor(sf::Color::Black);
        txt[0].setString("You are player 2 (WHITE):");
        txt[0].setPosition(cell_size*dimension,100);
        window.draw(txt[0]);

        txt[1].setCharacterSize(15);
        txt[1].setFont(font);
        txt[1].setFillColor(sf::Color::Black);
        char s[20]="Your score is : ";
        char sc[20];
        sprintf(sc,"%d",sp2);
        strcat(s,sc);
        txt[1].setString(s);
        txt[1].setPosition(cell_size*dimension,150);
        window.draw(txt[1]);
                   
        txt[2].setCharacterSize(15);
        txt[2].setFont(font);
        txt[2].setFillColor(sf::Color::Black);
        char s1[30]="Opponent's score is : ";
        char sc1[20];
        sprintf(sc1,"%d",sp1);
        strcat(s1,sc1);
        txt[2].setString(s1);
        txt[2].setPosition(cell_size*dimension,200);
        window.draw(txt[2]);
        }

        txt[3].setCharacterSize(15);
        txt[3].setFont(font);
        txt[3].setFillColor(sf::Color::Black);
        txt[3].setPosition(cell_size*dimension,250);
        if(t)
        {
        txt[3].setString("Your turn to move!");
        }
        else
        {
        txt[3].setString("Opponent's turn to move!");
        }
        window.draw(txt[3]);

        if(skip)
        {
                sf::Text tx;
                tx.setCharacterSize(15);
                tx.setFont(font);
                tx.setFillColor(sf::Color::Black);
                tx.setPosition(cell_size*dimension,300);
                tx.setString("Opponent skipped!");
                window.draw(tx);
        }
        
      
}

void draw_end(sf::RenderWindow &window)
{ 
          sf::Font font;
          sf::Text txt[2];
          if(!font.loadFromFile("/usr/share/fonts/truetype/fonts-deva-extra/samanata.ttf"))
                {
                  
                }
        txt[0].setCharacterSize(15);
        txt[0].setFont(font);
        txt[0].setFillColor(sf::Color::Black);
        txt[0].setString("The match is over!");
        txt[0].setPosition(cell_size*dimension,350);
        window.draw(txt[0]);

        txt[1].setCharacterSize(15);
        txt[1].setFont(font);
        txt[1].setFillColor(sf::Color::Black);
        txt[1].setString("Press backspace to continue!");
        txt[1].setPosition(cell_size*dimension,400);
        window.draw(txt[1]);

}
bool quit_game(sf::RenderWindow &window)
{
  sf::Event event;
    if(event.type==sf::Event::KeyReleased) 
                        {   if(event.key.code==sf::Keyboard::BackSpace) return true;}

    return false;                    

}
bool pass_move(sf::RenderWindow &window)
{
        sf::Event event;
        if(event.type==sf::Event::KeyReleased)
        {
                if(event.key.code==sf::Keyboard::Space) return true;
        }
        return false;
}

void draw_pieces(sf::RenderWindow &window)
{        
     
        sf::CircleShape bp(1.0*cell_size/2);
        sf::CircleShape wp(1.0*cell_size/2);
        bp.setFillColor(sf::Color::White);
        bp.setOutlineColor(sf::Color::Black);
        bp.setOutlineThickness(-2);
     
        wp.setFillColor(sf::Color::Black);
        wp.setOutlineThickness(-2);
        
        for(int y=0;y<dimension;y++)
          for(int x=0;x<dimension;x++)
            {
                    if(matrix[y][x]==1)
                    {
                        bp.setPosition(x*cell_size,y*cell_size);
                        window.draw(bp);
                       
                    }
                     if(matrix[y][x]==2)
                    {
                        wp.setPosition(x*cell_size,y*cell_size);
                        window.draw(wp);
                    }
            }
       
}
bool check(int color,int x,int y)
{
        if(visited[y][x])return false;
        visited[y][x]=true;

        if(matrix[y][x]==0)
        {
                return true;
        }
        if(matrix[y][x]!=color)return false;
        bool r=x>0 && check(color,x-1,y);
        r|=x<dimension-1 &&check (color,x+1,y);
        r|=x>0 && check(color,x,y-1);
        r|=y<dimension-1 &&check(color,x,y+1);
        return r;
}
  void remove(int color)
  {
          int capture[19][19]={0};
          for(int y=0;y<dimension;y++)
           for(int x=0;x<dimension;x++)
            {
                    if(matrix[y][x]!=color)continue;
                    for(int i=0;i<dimension;i++)
                    for(int j=0;j<dimension;j++)
                    visited[i][j]=false;
                    if(check(color,x,y)==false)capture[y][x]=1;
            }
            for(int y=0;y<dimension;y++)
             for(int x=0;x<dimension;x++)
              {       
                      if(capture[y][x]){matrix[y][x]=0;
                      if(color==1)sp1++;
                      else sp2++;}
              }
  }
  void reinit_game()
  {
          for(int i=0;i<19;i++)
          for(int j=0;j<19;j++)
          matrix[i][j]=0;
          sp1=0;
          sp2=0;
  }
  bool mouseInput(int &a,int &b,sf::RenderWindow &window,int color)
  {
  sf::Event event;
  while (window.pollEvent(event))
                {
                 if(event.type==sf::Event::MouseButtonPressed)
                        {      
                                 int x=event.mouseButton.x/cell_size;
                                 int y=event.mouseButton.y/cell_size;
                                 if(event.mouseButton.x>dimension*cell_size)
                                 return false;
                                 if(event.mouseButton.y>dimension*cell_size)
                                 return false;
                            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            {         if(matrix[y][x]!=0)
                                      return false;
                                      matrix[y][x]=color;
                                      quit=false;
                                      if(color==1)
                                      remove(2);
                                      else 
                                      remove(1);
                                      a=x;
                                      b=y;
                                      return true;
                                      
                            } 

                           
                            
                         }

                }
                return false;
  }

bool endgame(sf::RenderWindow &window)
  {       
     sf::Event event;
     while (window.pollEvent(event))
        if(event.type==sf::Event::KeyReleased)
        {
                if(event.key.code==sf::Keyboard::Space) return true;
        }
               window.clear();
                window.clear(sf::Color(255,207,97));
                draw_board(window);
                draw_score(window,p,false);
                draw_pieces(window);
                window.display();
                return false;
                             
  }

int main()
{   
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Menu");
    int Show=0;
       Menu menu(window.getSize().x,window.getSize().y);
       Options op(window.getSize().x,window.getSize().y);
       Play pl(window.getSize().x,window.getSize().y);
       FindingMatch find(window.getSize().x,window.getSize().y);
       Pquit yq(window.getSize().x,window.getSize().y,true);
       Pquit hq(window.getSize().x,window.getSize().y,false);

        while (window.isOpen()||isWindow)
        {
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                               { window.close(); isWindow=false;}
                     
                        if(event.type==sf::Event::KeyReleased) 
                        {  
                           if(event.key.code==sf::Keyboard::Up)
                           if(Show==0)
                           menu.MoveUp();
                           else
                           if(Show==1)
                           op.MoveUp();
                           else 
                           if(Show==2)
                           pl.MoveUp();
                          
                           if(event.key.code==sf::Keyboard::Down)
                           if(Show==0)
                           menu.MoveDown();
                           else
                           if(Show==1)
                           op.MoveDown();
                           else 
                           if(Show==2)
                           pl.MoveDown();

                            if((event.key.code==sf::Keyboard::BackSpace)&&(Show==7))
                            {       quit=false;
                                    Show=2;
                            }

                           if(event.key.code==sf::Keyboard::Return)
                           { 
                                   if(menu.getKey()==1&&Show==0)
                                   { 
                                     Show=1;
                                     menu.reIninit();
                                   }
                                   else
                                   if(op.getKey()==3&&Show==1)
                                   {
                                     Show=0;
                                     op.reIninit();
                                   }
                                   else
                                   if(op.getKey()==0&&Show==1)
                                   {
                                    dimension=9;
                                    Show=0;
                                    op.reIninit();
                                   }
                                   else
                                   if(op.getKey()==1&&Show==1)
                                   {
                                     dimension=13;
                                     Show=0;
                                     op.reIninit();
                                   }
                                   else
                                    if(op.getKey()==2&&Show==1)
                                   {
                                     dimension=19;
                                     Show=0;
                                     op.reIninit();
                                   }
                                   else
                                   if(menu.getKey()==0&&Show==0)
                                   {
                                     Show=2;
                                     menu.reIninit();
                                   }
                                   else
                                   if(pl.getKey()==2&&Show==2)
                                   {
                                     Show=0; 
                                   }
                                   else
                                   if(pl.getKey()==1&&Show==2)
                                   {
                                     Show=3;
                                     window.create(sf::VideoMode(cell_size*dimension+225, cell_size*dimension+50), "Go");
                                     reinit_game();
                                   }
                                   else
                                   if(menu.getKey()==2&&Show==0)
                                   {
                                    window.close();
                                    isWindow=false;
                                   }
                                   else
                                  if(pl.getKey()==0&&Show==2)
                                  { 
                                     
                                     window.clear();
                                     pl.reIninit();
                                     Show=4;
                                  }
                                  if(Show==5)
                                  {
                                          window.clear();
                                          yq.reIninit();
                                          Show=2;
                                  }
                                  if(Show==6)
                                  {
                                          window.clear();
                                          hq.reIninit();
                                          Show=2;
                                  }
                                  
                                  
                                   
                                  
                           }
                             if(event.key.code==sf::Keyboard::BackSpace&&Show==4)
                               {
                                     window.clear();
                                     window.create(sf::VideoMode(1024,768), "Go");
                                     window.clear();
                                     pl.reIninit();
                                     Show=2;
                                     aux=true;
                               }
                            
                        } 
                     
                }
        
        if(Show==0)
        {window.clear();
         menu.draw(window);
         window.display();
        }
        else
        if(Show==1)
        {
        window.clear();
        op.draw(window);
        window.display();
        }
        else
        if(Show==2)
        {
        while(aux)
         {window.create(sf::VideoMode(1024,768), "Go");aux=false;}
        window.clear();
        pl.draw(window);
        window.display();
        }
        else
        if(Show==5)
        { 
        window.clear();
        yq.draw(window);
        window.display();
        }
        else
        if(Show==6)
        {
                window.clear();
                hq.draw(window);
                window.display();
        }
        else
        if(Show==7)
        {       
                
                window.clear();
                window.clear(sf::Color(255,207,97));
                draw_board(window);
                draw_score(window,p,false);
                draw_end(window);
                draw_pieces(window);
                window.display();
                aux=true;
                
        }
        else
        if(Show==3)
        {       int x,y,c;
                bool pass=false;
                if(spcount%2==0){c=2;t=true;}
                else
                {c=1;t=false;}

                window.clear();
                window.clear(sf::Color(255,207,97));
                draw_board(window);
                draw_score(window,true,false);
                draw_pieces(window);
                window.display();
                
                while(!mouseInput(x,y,window,c))
                {
                        if(quit_game(window))
                        {
                                Show=5;
                                window.clear();
                                window.create(sf::VideoMode(1024,768), "Go");
                                yq.reIninit();
                                yq.draw(window);
                                reinit_game();
                                break;

                        }
                        if(pass_move(window))
                        {
                           pass=true;
                           break;
                        }
                }
                window.clear();
                window.clear(sf::Color(255,207,97));
                draw_board(window);
                draw_score(window,true,false);
                draw_pieces(window);
                window.display();
                if(!pass)
                matrix[y][x]=c;
                else
                pass=false;
                remove(1);
                remove(2);

                spcount++;

        }
        if(Show==4)
        { window.clear();
          find.draw(window);
          InQueue=true;
          window.display();     
         int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("Error in connection.\n");
		exit(1);
	}
	printf("Client Socket is created.\n");
        if(dimension==9)
        PORT=4441;
        else
        if(dimension==13)
        PORT=4442;
        else
        if(dimension==19)
        PORT=4443;

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("Error in connection.\n");
		exit(1);
	}
	printf("Connected to Server.\n");
         //get player id
                if(recv(clientSocket, buffer, 2, 0) < 0){
			printf("Error in receiving data.\n");
		}else{
			printf("Server: \t%s\n", buffer);
		}
                if(strstr(buffer,"1"))
                p=true;
                else
                p=false;
                //draw matrix
                window.create(sf::VideoMode(cell_size*dimension+225, cell_size*dimension+50), "Go");
                window.clear(sf::Color::Yellow);
                window.clear();
                window.clear(sf::Color(255,207,97));
               if(p)t=true;
                reinit_game();
               draw_board(window);
               draw_score(window,p,false);
               draw_pieces(window);
               window.display();
               bool run=true;
               if(p)
               {   
                  int color=2;
                  bool i=true;
                  bool ispass=false;
                  bool dr=false;
                while(run){
                  
                      int a,b;
                      char buff1[24];
                      char buff2[24];
                      char buff3[48];
                      char status[48];
                      int r=0,s=0;
                      sf::Event event;
                      while (window.pollEvent(event));
                      while(!mouseInput(a,b,window,color)&&i)
                      {
                              if(quit_game(window)||quit){
                              if(quit)
                              Show=7;
                              else 
                              Show=5;
                              run=false;
                              window.clear();
                              if(!quit)
                              window.create(sf::VideoMode(1024,768), "Go");
                              else
                              window.create(sf::VideoMode(cell_size*dimension+225, cell_size*dimension+50), "Go");

                              yq.reIninit();
                              window.clear();
                              yq.draw(window);
                              char q[10]="quit";
                              s=send(clientSocket, q, strlen(q), 0);
                              close(clientSocket);
                              if(!quit)
                              reinit_game();
                              quit=false;
                              break;
                              }
                              if(pass_move(window))
                              {
                                 ispass=true;
                                 quit=false;
                                 break;
                              }
                      }
                      if(!run)break;

                      i=false;
                      window.clear();
                      window.clear(sf::Color(255,207,97));
                      t=false;
                      draw_board(window);
                      draw_score(window,p,false);
                      draw_pieces(window);
                      window.display();

                      if(!ispass){
                      sprintf(buff1,"%d", a);
                      sprintf(buff2,"%d", b);
                      strcpy(buff3,buff1);
                      strcat(buff3," ");
                      strcat(buff3,buff2);
                      while(strlen(buff3)+1<=6)
                      strcat(buff3,"#");
                      s=send(clientSocket, buff3, 6, 0);
                                 }

                      else
                      s=send(clientSocket,"pass##",6,0);
                     
                     
                      bzero(buff1,sizeof(buff1));
                      bzero(buff2,sizeof(buff2));
                      bzero(buff3,sizeof(buff3));
                      t=false;
                      window.clear();
                      window.clear(sf::Color(255,207,97));
                      draw_board(window);
                      draw_score(window,p,false);
                      draw_pieces(window);
                      window.display();
                      r=recv(clientSocket,buff3,6,0);
                    
                       if(buff3[0]=='q')
                  {           if(Show!=7)
                              Show=6;
                              run=false;
                              close(clientSocket);
                              window.clear();
                              if(Show!=7)
                              window.create(sf::VideoMode(1024,768), "Go");
                              else
                              window.create(sf::VideoMode(cell_size*dimension+225, cell_size*dimension+50), "Go");
                              pl.reIninit();
                              if(Show!=7)
                              reinit_game();
                              break;
                  }
                     if(strstr(buff3,"pass"))
                     {
                             if(ispass)
                             {      
                                     
                                     quit=true;
                                     Show=7;

                             }
                             dr=true;
                     } 
                     else{

                      buff3[r]='\0';
                      char *pch;
                      pch=strstr(buff3," ");
                      strcpy(buff2,pch+1);
                      strncpy(buff1,buff3,strlen(buff3)-strlen(pch));
                      for(int i=0;i<strlen(buff2);i++)
				 {
					 if(buff2[i]=='#'){buff2[i]='\0';break;}
				 }


                      a=atoi(buff1);
                      b=atoi(buff2);
                      if(a>dimension)a=a/10;
                      matrix[b][a]=1;
                      remove(2);
                      remove(1);

                      quit=false;
                     }
                      t=true;
                      window.clear();
                      window.clear(sf::Color(255,207,97));
                      draw_board(window);
                      if(!dr)
                      draw_score(window,p,false);
                      else
                      {draw_score(window,p,true);dr=false;}
                      draw_pieces(window);
                      window.display();
                      i=true;
                      r=0;
                      ispass=false;
                      
                    
                 }
               }
                 else
              if(!p)
               {  int color=1;
                  bool i=true;
                  bool ispass=false;
                  bool pass=false;
                  bool snd=false;
                  bool dr=false;
                while(run){
                 t=false;
                  window.clear();
                  window.clear(sf::Color(255,207,97));
                  draw_board(window);
                  draw_score(window,p,false);
                  draw_pieces(window);
                  window.display();

                  int a,b;
                  char buff1[24];
                  char buff2[24];
                  char buff3[48];
                  char garbage[48];
                  int r=0,s=0;
                  r=recv(clientSocket,buff3,6,0);
                  if(buff3[0]=='q')
                  {           if(quit)
                              Show=7;
                              else
                              Show=6;
                              run=false;
                              close(clientSocket);
                              window.clear();
                              
                              if(!quit)
                              window.create(sf::VideoMode(1024,768), "Go");
                              else
                              window.create(sf::VideoMode(cell_size*dimension+225, cell_size*dimension+50), "Go");
                              pl.reIninit();
                              if(Show!=7)
                              reinit_game();
                              break;
                  }
                  quit=false;
                  if(strstr(buff3,"pass"))
                  {
                          ispass=true;
                          dr=true;
                  }


                
                 if(!ispass){
                  buff3[r]='\0';
                  char *pch;
                  pch=strstr(buff3," ");
                  strcpy(buff2,pch+1);
                  strncpy(buff1,buff3,strlen(buff3)-strlen(pch));
                  for(int i=0;i<strlen(buff2);i++)
				 {
					 if(buff2[i]=='#'){buff2[i]='\0';break;}
				 }
                  
                  a=atoi(buff1);
                  b=atoi(buff2);
                  if(a>dimension)a=a/10;
                  matrix[b][a]=2;
                  remove(1);
                  remove(2);
                  quit=false;
                            }
                  t=true;
                  window.clear();
                  window.clear(sf::Color(255,207,97));
                  draw_board(window);
                  if(!dr)
                  draw_score(window,p,false);
                  else
                  draw_score(window,p,true);
                  draw_pieces(window);
                  window.display();
              
                     

                 bzero(buff1,sizeof(buff1));
                 bzero(buff2,sizeof(buff2));
		 bzero(buff3,sizeof(buff3));
                  i=true;
                  sf::Event event;
                  while (window.pollEvent(event));
                  while(!mouseInput(a,b,window,color)&&i)
                  {
                              if(pass_move(window))
                              { 
                                 if(ispass){snd=true; quit=true;}
                                 else
                                {pass=true;snd=true;draw_score(window,p,true);quit=false;}
                                 break;
                              }
                              else 
                              {
                                      if(ispass&&pass)
                                      {
                                              
                                              quit=true;
                                              pass=false;
                                              snd=true;
                                              Show=7;
                                              break;
                                      }
                              }



                              if(quit_game(window)||quit){

                              if(quit)
                              Show=7;
                              else
                              Show=5;

                              run=false;
                              window.clear();
                              if(!quit)
                              window.create(sf::VideoMode(1024,768), "Go");
                              else
                              window.create(sf::VideoMode(cell_size*dimension+225, cell_size*dimension+50), "Go");

                              yq.reIninit();
                              window.clear();
                         
                              char q[10]="quit";
                              s=send(clientSocket, q, strlen(q), 0);
                              close(clientSocket);
                              if(Show!=7)
                              reinit_game();
                              break;
                              }
                               
                  }
                  
                  i=false;
                  window.clear();
                  window.clear(sf::Color(255,207,97));
                  draw_board(window);
                  if(!dr)
                  draw_score(window,p,false);
                  else
                  {draw_score(window,p,true);dr=false;}
                  draw_pieces(window);
                  window.display();
                  if(!snd){
                  sprintf(buff1,"%d", a);
                  sprintf(buff2,"%d", b);
                  strcpy(buff3,buff1);
                  strcat(buff3," ");
                  strcat(buff3,buff2);
                  while(strlen(buff3)+1<=6)
                  strcat(buff3,"#");
                  s=send(clientSocket, buff3, 6, 0);
                  pass=false;}
                  else
                  {s=send(clientSocket,"pass##",6,0);snd=false;}
                  ispass=false;
                  
               }
               }

        
         
        }
      
     }
       
   }