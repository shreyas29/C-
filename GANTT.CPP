# include <iostream.h>
# include <stdlib.h>
# include <conio.h>
# include <graphics.h>
# include <dos.h>

void fcfs(); void sjf(); void srtf(); void rr(); int totaltime();
void print_gtable(); void graphicize();

int n;
int tab[6][3]={0};
int ttt=0;
int gtable[20][3]={0};
int gsize=0;
char choice;

void print_gtable()
{
	int i;
	for(i=0;i<gsize;i++)
	{
		cout << gtable[i][0] << "  ";
		cout << gtable[i][1] << "  ";
		cout << gtable[i][2] << "\n";
	}
}

int totaltime()
{
	int s;int ans=0;
	for(s=0;s<n;s++)
	ans=ans+tab[s][2];
	return ans;
}

void fcfs()
{
	int k=0,gs=0;
	for(k=0;k<n;k++)
	{
		gtable[k][0] = k+1;
		gtable[k][1] = gs;
		gtable[k][2] = gs + 20*tab[k][2];
		gs = gtable[k][2];
		gsize++;
	}
	// FCFS gtable Works Okay...
	//	print_gtable();
	//	getch();
	graphicize();
}

void graphicize()
{
    clrscr();
    int gd = DETECT, gm, errorcode;
    int rect[8]={0};
    initgraph(&gd, &gm, "c://turboc3/tc/bgi");
    errorcode = graphresult();
    if (errorcode != grOk)
    {
       cout << ":: Graphics error ::";
       cout << "\nCheck the BGI Directory Path for Graphics Files";
       getch();
       exit(1);
    }
    int gmx=getmaxx();
    int gmy=getmaxy();
    setviewport((gmx-600)/2, (gmy-200)/2, ((gmx-600)/2)+600, ((gmy-200)/2)+200, 1);
    setbkcolor(3);
    setcolor(1);
    line(0,0,600,0);line(0,30,600,30);line(0,60,600,60);
    line(0,90,600,90);line(0,120,600,120);line(0,150,600,150);
    line(0,180,600,180);
    int r;

    int l;
    for(l=0;l<gsize;l++)
    {
	rect[0]=gtable[l][1];
	rect[1]=(gtable[l][0]-1)*30;
	rect[2]=gtable[l][2];
	rect[3]=(gtable[l][0]-1)*30;
	rect[4]=gtable[l][2];
	rect[5]=gtable[l][0]*30;
	rect[6]=gtable[l][1];
	rect[7]=gtable[l][0]*30;
	setfillstyle(SOLID_FILL,6);
	fillpoly(4,rect);
    }
    setviewport((gmx-600)/2+3, (gmy-200)/2-20, ((gmx-600)/2)+600, ((gmy-200)/2)+200, 1);
    outtextxy(0,5,"01");
    outtextxy(20,5,"02");
    outtextxy(40,5,"03");
    outtextxy(60,5,"04");
    outtextxy(80,5,"05");
    outtextxy(100,5,"06");
    outtextxy(120,5,"07");
    outtextxy(140,5,"08");
    outtextxy(160,5,"09");
    outtextxy(180,5,"10");
    outtextxy(200,5,"11");
    outtextxy(220,5,"12");
    outtextxy(240,5,"13");
    outtextxy(260,5,"14");
    outtextxy(280,5,"15");
    outtextxy(300,5,"16");
    outtextxy(320,5,"17");
    outtextxy(340,5,"18");
    outtextxy(360,5,"19");
    outtextxy(380,5,"20");
    outtextxy(400,5,"21");
    outtextxy(420,5,"22");
    outtextxy(440,5,"23");
    outtextxy(460,5,"24");
    outtextxy(480,5,"25");
    outtextxy(500,5,"26");
    outtextxy(520,5,"27");
    outtextxy(540,5,"28");
    outtextxy(560,5,"29");
    outtextxy(580,5,"30");
    setviewport((gmx-600)/2, (gmy-200)/2-20, ((gmx-600)/2)+600, ((gmy-200)/2)+200, 1);
    line(0,0,600,0);
    for(r=0;r<31;r++)
    {
	line(20*r,0,20*r,200);
    }

    setviewport((gmx-600)/2, 50 , ((gmx-600)/2)+600, ((gmy-200)/2)+200, 1);
    setcolor(4);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtext("GANNT CHART");
    setviewport((gmx-600)/2, 80 , ((gmx-600)/2)+600, ((gmy-200)/2)+200, 1);
    setcolor(8);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    outtext("No. of Processes : ");

    if(n==1) outtext("1");
    if(n==2) outtext("2");
    if(n==3) outtext("3");
    if(n==4) outtext("4");
    if(n==5) outtext("5");
    if(n==6) outtext("6");
    setviewport((gmx-600)/2, 100 , ((gmx-600)/2)+600, ((gmy-200)/2)+200, 1);

    outtext("Scheduling Method : ");
    if(choice=='1') outtext("FCFS - First Come First Serve");
    if(choice=='2') outtext("SJF - Shortest Job First");
    if(choice=='3') outtext("SRTF - Shortest Remaining Time First");
    if(choice=='4') outtext("RR - Round Robin");
    setviewport((gmx-600)/2-10, (gmy-200)/2, ((gmx-600)/2)+600, ((gmy-200)/2)+200, 1);
    setcolor(1);
    outtextxy(0,25-15,"1");
    outtextxy(0,55-15,"2");
    outtextxy(0,85-15,"3");
    outtextxy(0,115-15,"4");
    outtextxy(0,145-15,"5");
    outtextxy(0,175-15,"6");

    getch();
    closegraph();
}

void sjf()
{
	int cur=0,lt=999,et=0,gs=0,i,j;
	for(i=0;i<n;i++)
	{
		cur=0;lt=999;
		for(j=0;j<n;j++)
		{
			if(tab[j][1]<=et)
			{
				if(tab[j][2]!=0)
				{
					if(tab[j][2]<lt)
					{
						cur=j;
						lt=tab[j][2];
					}
				}
			}
		}
		gtable[i][0]=cur+1;
		gtable[i][1]=gs;
		gtable[i][2]=gs + 20 * tab[cur][2];
		gsize++;
		gs=gtable[i][2];
		et=et+tab[cur][2];
		tab[cur][2]=0;
	}
	// SJF gtable works okay....
	graphicize();
}

void srtf()
{
	int cur=0,lt=999,et=0,gs=0,i,j;
	for(i=0;i<ttt;i++)
	{
	     cur=0;lt=999;
	     for(j=0;j<n;j++)
	     {
		if(tab[j][1]<=et)
		{
		   if(tab[j][2]!=0)
		   {
		      if(tab[j][2]<lt)
		      {
			cur=j;
			lt=tab[j][2];
		      }
		   }
		}
	     }
	     gtable[i][0]=cur+1;
	     gtable[i][1]=gs;
	     gtable[i][2]=gs+20;
	     gsize++;
	     gs=gs+20;
	     et++;
	     tab[cur][2]=tab[cur][2]-1;
	}
	// SRTF gtable works okay...
	graphicize();
}

void rr()
{
	int q;
	cout << "\nEnter the Quantum Size : ";
	cin >> q;
	int cur=-1,et=0,gs=0,gvar=0;
	while(et<ttt)
	{
		cur++;
		if(cur==n) cur=0;

		if(tab[cur][1]<=et)
		{
		   if(tab[cur][2]!=0)
		   {
			gvar++;

			if(tab[cur][2]<q)
			{
			et=et+tab[cur][2];
			gtable[gvar-1][0]=cur+1;
			gtable[gvar-1][1]=gs;
			gtable[gvar-1][2]=gs + tab[cur][2] * 20;
			gs=gtable[gvar-1][2];
			gsize++;
			tab[cur][2]=0;
			}
			else
			{
			et=et+q;
			gtable[gvar-1][0]=cur+1;
			gtable[gvar-1][1]=gs;
			gtable[gvar-1][2]=gs + q*20;
			gsize++;
			gs=gtable[gvar-1][2];
			tab[cur][2]=tab[cur][2]-q;
			}
		   }
		}
	}
	// RR gtable works okay...
	graphicize();
}

void main()
{
	clrscr();
	cout << "Enter the Number of Process : ";
	cin >> n;

	cout << "\n\n1) FCFS   2) SJF   3) SRTF   4) RR\n\n";
	cout << "Enter Your Choice : ";
	cin >> choice;

	cout << "\n";
	int i;
	for(i=0;i<n;i++)
	{
	cout << "Arrival Time & Service Time for Process " << i+1 << " : ";
	tab[i][0]=i+1;
	cin >> tab[i][1];
	cin >> tab[i][2];
	}
	ttt=totaltime();
	switch(choice)
	{
		case '1': fcfs();break;
		case '2': sjf();break;
		case '3': srtf();break;
		case '4': rr();break;
		default : exit(0);
	}

}