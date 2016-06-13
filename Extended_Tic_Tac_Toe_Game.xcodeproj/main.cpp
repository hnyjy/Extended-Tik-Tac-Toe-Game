//
//  main.cpp
//  HW02(Jingyi Yang)
//
//  Created by yangjingyi on 14/10/21.
//  Copyright (c) 2014年 yangjingyi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <time.h>


using namespace std;

class player
{
public:
    string name;
    //vector<int> step[2];
    vector<vector<int> > step;
    
public:
    void get_step(int i, int j)
    {
        step[0].push_back(i);
        step[1].push_back(j);
    }
    void print_step()
    {
        int k;
        for(k=0;k<step[0].size();k++)
        {
            cout << step[0][k]<<endl;
            cout << step[1][k]<<endl;
            
        }
    }
    player();
    player(string nm);
    
};
player::player()
{
    name='0';
    step=vector<vector<int> >(2);
    step[0].resize(0);
    step[1].resize(0);
}
player::player(string nm)
{
    name=nm;
    step=vector<vector<int> >(2);
    step[0].resize(0);
    step[1].resize(0);
};

    
void display(int n, int m, vector<vector<string> > display_board)
{
    int row=0, col=0;
    cout<<" ";
    for(col=0;col<m;col++)
    {
        cout<<" "<< col+1 << "  ";
    }
    cout<<endl;
    for(row=0;row<n-1;row++)
    {
        cout<<row+1;
        for(col=0;col<m-1;col++)
        {
            cout <<" " << display_board[row][col] << " "<<"|";
        }
        cout << display_board[row][m-1]<<endl;
        cout <<" ";
        for(col=0;col<m-1;col++)
        {
            cout <<"---+";
        }
        cout << "---"<<endl;
    }
    cout << n;
    for(col=0;col<m-1;col++)
    {
        cout <<" "<<display_board[n-1][col]<<" "<<"|";
        
    }
    cout <<" "<<display_board[n-1][m-1]<<" "<<endl;
}


vector<vector<int> > con_hor(int hor_x,int hor_y,int hor_count)
{
    //int* a = new int[2][hor_count];
    vector<vector<int> > const_hor(2);
    int hor_num;
    for(hor_num=0;hor_num<hor_count;hor_num++)
    {
        const_hor[0].push_back(hor_x);
        const_hor[1].push_back(hor_y+hor_num);
        cout << const_hor[0][hor_num]<<"+";
        cout << const_hor[1][hor_num]<<endl;
    }
    return const_hor;
}

vector<vector<int> > con_ver(int ver_x, int ver_y, int ver_count)
{
    vector< vector< int> > const_ver(2);
    int ver_num;
    for(ver_num=0;ver_num<ver_count; ver_num++)
    {
        const_ver[0].push_back(ver_x+ver_num);
        const_ver[1].push_back(ver_y);
        cout << const_ver[0][ver_num]<<"+";
        cout << const_ver[1][ver_num]<<endl;
    }
    return const_ver;
}
vector<vector<int> > con_riup(int riup_x, int riup_y, int riup_count)
{
    vector<vector<int> > const_riup(2);
    int riup_num;
    for(riup_num=0;riup_num<riup_count;riup_num++)
    {
        const_riup[0].push_back(riup_x-riup_num);
        const_riup[1].push_back(riup_y+riup_num);
        cout << const_riup[0][riup_num]<<"+";
        cout << const_riup[1][riup_num]<<endl;
    }
    return const_riup;
}

vector<vector<int> > con_ridown(int ridown_x, int ridown_y, int ridown_count)
{
    vector<vector<int> > const_ridown(2);
    int ridown_num;
    for(ridown_num=0;ridown_num<ridown_count;ridown_num++)
    {
        const_ridown[0].push_back(ridown_x+ridown_num);
        const_ridown[1].push_back(ridown_y+ridown_num);
        cout << const_ridown[0][ridown_num]<<"+";
        cout << const_ridown[1][ridown_num]<<endl;
    }
    return const_ridown;
}

vector<vector<int> > con_squ(int squ_x, int squ_y, int squ_count)
{
    vector<vector<int> > const_squ(2);
    int squ_num;
    for(squ_num=0;squ_num<(squ_count-2);squ_num++)
    {
        const_squ[0].push_back(squ_x);
        const_squ[1].push_back(squ_y+squ_num);
    }
    for(squ_num=0;squ_num<(squ_count-2);squ_num++)
    {
        const_squ[0].push_back(squ_x+squ_num);
        const_squ[1].push_back(squ_y+squ_count-2);
    }
    for(squ_num=0;squ_num<(squ_count-2);squ_num++)
    {
        const_squ[0].push_back(squ_x+squ_count-2);
        const_squ[1].push_back(squ_y+squ_count-2-squ_num);
    }
    for(squ_num=0;squ_num<(squ_count-2);squ_num++)
    {
        const_squ[0].push_back(squ_x+1+squ_num);
        const_squ[1].push_back(squ_y);
    }
    for(squ_num=0;squ_num<const_squ[0].size();squ_num++)
    {
        cout << const_squ[0][squ_num] <<"+";
        cout << const_squ[1][squ_num] <<endl;
    }
    return const_squ;
}

int check_result(int temp_x,int temp_y,int count_sequence,vector<vector<int> > player_steps)
{
    int result_flag=0;
    int vec_num;
    int step_num;
    int equ_num=0;
    vector<vector<int> > check_vec;
    //hor.resize(count_sequence);
    check_vec=con_hor(temp_x,temp_y, count_sequence);
    for(vec_num=0;vec_num<check_vec[0].size();vec_num++)
    {
        for(step_num=0;step_num<player_steps[0].size();step_num++)
        {
            if(check_vec[0][vec_num]==player_steps[0][step_num]&&check_vec[1][vec_num]==player_steps[1][step_num])
               equ_num++ ;
            else
                continue;
                
        }
    }
    if(equ_num==check_vec[0].size())
    {
        result_flag=1;
        return result_flag;
    }
    else
        result_flag=0;
    equ_num=0;
    check_vec.clear();
    check_vec=con_ver(temp_x,temp_y, count_sequence);
    cout<<con_ver(temp_x,temp_y, count_sequence).size()<<endl;
    cout<<check_vec[0].size()<<endl;
    for(vec_num=0;vec_num<check_vec[0].size();vec_num++)
    {
        for(step_num=0;step_num<player_steps[0].size();step_num++)
        {
            if(check_vec[0][vec_num]==player_steps[0][step_num]&&check_vec[1][vec_num]==player_steps[1][step_num])
            {
                equ_num++ ;
                cout <<check_vec[0][vec_num]<<"and"<<check_vec[1][vec_num]<<endl;
            }
            else
                continue;
            
        }
    }
    if(equ_num==check_vec[0].size())
    {
        cout<<"equ"<<equ_num<<endl;
        //cout<<equ_num<<"="<<check_vec.size()<<endl;
        result_flag=1;
        return result_flag;
    }
    else
        result_flag=0;
    equ_num=0;
    check_vec.clear();
    check_vec=con_riup(temp_x,temp_y, count_sequence);
    for(vec_num=0;vec_num<check_vec[0].size();vec_num++)
    {
        for(step_num=0;step_num<player_steps[0].size();step_num++)
        {
            if(check_vec[0][vec_num]==player_steps[0][step_num]&&check_vec[1][vec_num]==player_steps[1][step_num])
                equ_num++ ;
            else
                continue;
            
        }
    }
    if(equ_num==check_vec[0].size())
    {
        result_flag=1;
        return result_flag;
    }
    else
        result_flag=0;
    equ_num=0;
    check_vec.clear();
    check_vec=con_ridown(temp_x,temp_y, count_sequence);
    for(vec_num=0;vec_num<check_vec[0].size();vec_num++)
    {
        for(step_num=0;step_num<player_steps[0].size();step_num++)
        {
            if(check_vec[0][vec_num]==player_steps[0][step_num]&&check_vec[1][vec_num]==player_steps[1][step_num])
                equ_num++ ;
            else
                continue;
            
        }
    }
    if(equ_num==check_vec[0].size())
    {
        result_flag=1;
        return result_flag;
    }
    else
        result_flag=0;
    equ_num=0;
    check_vec.clear();
    check_vec=con_squ(temp_x,temp_y, count_sequence);
    for(vec_num=0;vec_num<check_vec[0].size();vec_num++)
    {
        cout << "vec_num"<<vec_num<<endl;
        for(step_num=0;step_num<player_steps[0].size();step_num++)
        {
            cout<<player_steps[0][step_num]<<":"<<player_steps[1][step_num]<<endl;
            if(check_vec[0][vec_num]==player_steps[0][step_num]&&check_vec[1][vec_num]==player_steps[1][step_num])
            {
                equ_num++ ;
                cout<<"equ_num"<<equ_num<<endl;
                cout <<check_vec[0][vec_num]<<"and"<<check_vec[1][vec_num]<<endl;
            }
            
            
        }
    }
    if(equ_num==check_vec[0].size())
    {
        cout<<"check_vec"<<check_vec[0].size() << endl;
        result_flag=1;
        return result_flag;
    }
    else
        result_flag=0;
    equ_num=0;
    check_vec.clear();
    return result_flag;
};

bool check_playernum(int brow,int bcol,int playernum)
{
    if(0<playernum&&playernum<=brow*playernum<=bcol&&playernum<=26)
    {
        return true;
    }
    else
        return false;
}

bool check_seq(int brow1, int bcol1, int sequ)
{
    if(sequ>0&&sequ<=brow1&&sequ<=bcol1)
        return true;
    else
        return false;
}

bool check_rowandcol(int brow2, int bcol2)
{
    if(brow2<=0||bcol2<=0)
       return false;
    else
       return true;
}
bool check_step(int stepx,int stepy,vector<vector<string> > steps,int brow3,int bcol3)
{
    if(stepx<=brow3&&stepy<=bcol3&&steps[stepx-1][stepy-1]==" ")
    return true;
    else
    return false;
}

int main()
{
    int board_row=0, board_col=0;
    int x,y;
    int i,j;
    int count=0;
    int win_flag=0;
    int seq;
    int seq_count;
    string stepx;
    string stepy;
    string stepname;
    string steptime;
    string temp1;
    vector<vector<string> > board;
    vector<int> gamedata;
    vector<vector<int> > all_step;
    all_step.resize(3);
    vector<int> time_step;
    
    string ans;
    string player_name[26]={"X","O","A","B","C","D","E","F","G","H","I","J","K","L","M","N","P","Q","R","S","T","U","V","W","Y","Z"};
    vector<player> player_list;
    int player_num;
    
    
    do
    {
        cout<<"Do you want to resume a saved game?(Y/N)"<<endl;
        cin>>ans;
        cin.clear();
        cin.ignore(100000,'\n');
    }
    while(ans!="Y"&&ans!="N");
    if(ans=="Y")
    {
        string ifilename1="/Users/yangjingyi/Desktop/gamedata1.txt";
       fstream infile1(ifilename1);
       if(!infile1)
       {
           cout<<"There is no saved game."<<endl;
       }
       else
      {
        while(infile1>>temp1)
          {
              gamedata.push_back(atoi(temp1.c_str()));
          }
          board_row=gamedata[0];
          board_col=gamedata[1];
          player_num=gamedata[2];
          seq=gamedata[3];
          seq_count=gamedata[4];
          board.resize(board_row);
          for(i=0;i<board_row;i++)
          {
              board[i].resize(board_col);
              for(j=0;j< board_col;j++)
              {
                  board[i][j]=" ";
              }
          }
          for(i=0;i<player_num;i++)
          {
              player oth(player_name[i]);
              player_list.push_back(oth);
          }
          
              string ifilename2="/Users/yangjingyi/Desktop/gamedata2.txt";
              fstream ifile2(ifilename2);
              if(!ifile2)
              {
                  cout<<"There is no saved game."<<endl;
              }
              else
              {
                  while(ifile2>>stepx>>stepy>>steptime)
                  {
                      all_step[0].push_back(atoi(stepx.c_str()));
                      all_step[1].push_back(atoi(stepy.c_str()));
                      all_step[2].push_back(atoi(steptime.c_str()));
                  }
                  for(i=0;i<all_step[0].size();i++)
                  {
                      player_list[i%player_num].get_step(all_step[0][i],all_step[1][i]);
                  
                      //board[all_step[0][i]-1][all_step[1][i]-1]=player_name[i%player_num];
                  
                  }
                  
              }
          
          do
          {
              cout<<"Do you want to replay the saved game?"<<endl;
              cin.clear();
              cin.ignore(100000,'\n');
          }
          while(ans!="Y"&&ans!="N");
          if(ans=="Y")
          {
               for(i=0;i<all_step[0].size();i++)
                  {
                      board[all_step[0][i]-1][all_step[1][i]-1]=player_name[i%player_num];
                      display(board_row,board_col,board);
                    
                  }
                  
              
          }
      }
    }
}

        
    
    /*else
    {
    do
        {
            
        cout << "please input the row and column of the board:" << endl;
        cin >> board_row >> board_col;
        cin.clear();
        cin.ignore(100000,'\n');
        }
        while(!check_rowandcol(board_row, board_col));
        do
    {
        cout << "please input the number of the player"<<endl;
        cin >>player_num;
        cin.clear();
        cin.ignore(100000,'\n');
    }
    while(!check_playernum(board_row,board_col,player_num));
    do
    {
      cout <<"please input the number of sequence"<<endl;
      cin >> seq;
      cin.clear();
      cin.ignore(100000,'\n');
    }
    while(!check_seq(board_row,board_col, seq));
    
    int i,j;
    board.resize(board_row);
    for(i=0;i<board_row;i++)
    {
        board[i].resize(board_col);
        for(j=0;j< board_col;j++)
        {
            board[i][j]=" ";
        }
    }
    display(board_row,board_col,board);
    //player_list.resize(player_num);
    for(count=0;count<player_num;count++)
    {
        player oth(player_name[count]);
        player_list.push_back(oth);
    }
        while(win_flag==0)
    {
        for(count=0;count<player_num;count++)
        {
            int step_no=0;
            do
            {
               cout<<"please enter the location of the player"<<player_name[count]<<endl;
               cin>>x>>y;
               cin.clear();
               cin.ignore(100000,'\n');
            }
            while(!check_step(x,y,board,board_row,board_col));
            board[x-1][y-1]=player_name[count];
            display(board_row,board_col,board);
            all_step[0].push_back(x);
            all_step[1].push_back(y);
            player_list[count].get_step(x,y);
            player_list[count].print_step();
            //cout<<player_list[count].step[0][0]<<endl;
            //cout<<player_list[count].step[1][0]<<endl;
            for(step_no=0;step_no<player_list[count].step[0].size();step_no++)
            {
               win_flag=check_result((player_list[count].step[0][step_no]),(player_list[count].step[1][step_no]),seq,player_list[count].step);
                if(win_flag==1)
                {
                    cout << player_name[count] << "wins the game."<<endl;
                    break;
                }
                
            }
            
            if(all_step[0].size()==board_row*board_col)
            {
                win_flag=2;
                cout<< "The game ends in a draw. "<<endl;
                break;
            }
            else
                continue;
        }
    }
}
}*/
