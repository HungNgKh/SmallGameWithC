#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

int i,j,k;

void score(int x,int y)
{
	system("cls");
	printf("\n%56s\n\n\n","--------BANG THANH TICH--------");
	printf("*\t\tSO TRAN DA CHOI:%6d\n\n\n",y);
	printf("*\t\tSO TRAN THANG:%8d\n\n\n",x);
	if(y==0)
		printf("*\t\tTI LE THANG:%10s\n\n\n","\NA");
	else
		printf("*\t\tTI LE THANG:%10.2f %%\n\n\n",(float)x*100/y);
	printf("%52s\n","BAM ENTER DE TIEP TUC...");
	while(getch()!=13);
}

void ai(int a[])
{
	int b,x=0;
	printf("%40s","|");
	Sleep(250);printf("\b/");
	Sleep(250);printf("\b-");
	Sleep(250);printf("\b\\");
	Sleep(250);printf("\b|");
	if(a[0]+a[1]+a[2]==15){b=rand()%3;x=1;}
	else
	{
		for(i=0;i<3&&x==0;i++)
		{
		j=((i+1))%3;k=((i+2))%3;
		if(a[i]==a[j]&&a[k]>0&&a[i]>1){b=k;x=a[k];break;}
		if(a[i]==0&&a[j]>1&&a[j]<a[k]){b=k;x=a[k]-a[j];break;}
		if(a[i]>1&&a[j]==0&&a[i]<a[k]){b=k;x=a[k]-a[i];break;}
	 	if(((a[i]==2&&a[j]==4)||(a[i]==4&&a[j]==2))&&a[k]>6){b=k;x=a[k]-6;break;}
	 	if(((a[i]==4&&a[j]==6)||(a[i]==6&&a[j]==4))&&a[k]>2){b=k;x=a[k]-2;break;}
		if(((a[i]==2&&a[j]==6)||(a[i]==6&&a[j]==2))&&a[k]>4){b=k;x=a[k]-4;break;}
		if(((a[i]==1&&a[j]==4)||(a[i]==4&&a[j]==1))&&a[k]>5){b=k;x=a[k]-5;break;}
	 	if(((a[i]==1&&a[j]==5)||(a[i]==5&&a[j]==1))&&a[k]>4){b=k;x=a[k]-4;break;}
		if(((a[i]==4&&a[j]==5)||(a[i]==5&&a[j]==4))&&a[k]>1){b=k;x=a[k]-1;break;}
		if(((a[i]==1&&a[j]==2)||(a[i]==2&&a[j]==1))&&a[k]>3){b=k;x=a[k]-3;break;}
		if(((a[i]==1&&a[j]==3)||(a[i]==3&&a[j]==1))&&a[k]>2){b=k;x=a[k]-2;break;}
	 	if(((a[i]==2&&a[j]==3)||(a[i]==3&&a[j]==2))&&a[k]>1){b=k;x=a[k]-1;break;}
		if(a[i]==a[j]&&a[j]==1&&a[k]>1){b=k;x=a[k]-1;break;}
		if(a[i]==0&&a[j]==1&&a[k]>0){b=k;x=a[k];break;}
		if(a[i]==1&&a[j]==0&&a[k]>0){b=k;x=a[k];break;}
		if(a[i]==a[j]&&a[j]==0&&a[k]>0){b=k;x=a[k]-1;break;}
		}
		if(x==0)
		{
			do
		 		b=rand()%3;
 			while(a[b]<=0);
 			x=1;
		}
	}
	a[b]-=x;
}

void draw2(int a[],int b)
{
	int x;
	system("cls");
	for(i=0;i<10;i++)
	{
		printf("\n     ");
		for(k=0;k<3;k++)
		{
			x=10-a[k];
			for(j=0;j<20;j++)
				if(i==0||i==9||j==0||j==19) printf("\\");
				else if(i>1&&i<8&&(j-x)%2==0&&j>=x&&j<19-x) 
					if(i==2) printf("@");
					else printf("|");
				else printf(" ");
			printf("    ");
		}
	}
	printf("\n\n\t      ");
	printf("%d%23s%d%23s%d",a[0]," ",a[1]," ",a[2]);
	printf("\n");
	for(i=0;i<2;i++)
	{
		printf("\n\t     ");
		for(j=0;j<3;j++)
			if(j==b)
				switch(i)
				{
					case 0:printf(" ^ ");break;
					case 1:printf(" | ");break;
				}
			else printf("%24s"," ");
	}
}

int game(int d)
{
	char y[2][6]={"THANG","THUA"},n[2][4]={"MAY","BAN"};
	int c,b=0,a[3]={3,5,7},x=0;
	do
	{
		if(d==1)
		{
		do
		{
			do
			{
				draw2(a,b);
				printf("\n\n%30s---DEN LUOT %s---\n\n\n"," ",n[d]);
				do
					c=getch();
				while(c!=224&&c!=13);
				if(c==224)
				switch(getch())
				{
					case 77:case 72:b=(b+1)%3;break;
					case 75:case 80:b=(b+2)%3;break;
				}
			}while(c!=13);
			printf("\n\t\t\tNhap so diem muon rut:");
			scanf("%d",&x);	
			if(x<=0||x>a[b])
			{
				printf("KO HOP LE!!!");
				Sleep(750);
			}
		}while(x<=0||x>a[b]);
		a[b]-=x;
		}
		else 
		{
			draw2(a,b);
			printf("\n\n%30s---DEN LUOT %s---\n\n\n"," ",n[d]);
			ai(a);
		}
		d=1-d;
	}while(a[0]+a[1]+a[2]>1);
	draw2(a,b);
	if(a[0]+a[1]+a[2]==1) 
			printf("\n\n\n%32sBAN DA %s!\n"," ",y[d]);
	else printf("\n\n\n%32sBAN DA %s!\n"," ",y[1-d]);
	puts("\n\n\t\t\t\tBAM ENTER DE QUAY LAI!...");
	while(getch()!=13);
	return d;
}

void draw(int a,int b)
{
	char c[3][5]={"BUA","KEO","GIAY"};
	system("cls");
	printf("\n%65s\n\n\n","--------OAN TU TI XEM THANG` NAO` RUT TRUOC--------");
	if(b<3)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<3;j++)
				if(j==b)
					switch(i)
					{
						case 0:printf("%21s"," MAY ");break;
						case 1:printf("%21s","     ");break;
						case 2:printf("%59s"," ||| ");break;
						case 3:printf("%40s\n","  |  ");break;
					}
				else printf("%20s"," ");
		}
		printf("\n");
	}
	else printf("\n\n\n\n\n");
	printf("%21s%20s%20s\n","@@@@ ","@   @","@@@@  ");
	printf("%21s%20s%20s\n","@@@@@"," @ @ ","@  @@ ");
	printf("%21s%20s%20s\n"," @@  ","  @  ","@  @@@");
	printf("%21s%20s%20s\n"," @@  "," @ @ ","@    @");
	printf("%21s%20s%20s\n"," @@  ","@@ @@","@@@@@@");
	printf("\n%20s%20s%20s\n\n",c[0],c[1],c[2]);
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j==a)
				switch(i)
				{
					case 0:printf("%21s","  ^  ");break;
					case 1:printf("%21s"," BAN ");
				}
			else printf("%20s"," ");
		}
		printf("\n\n");
	}
}

int oantuti()
{

	int x,a=0,b,d;
	do
	{
		b=3;
		do
		{
			draw(a,b);
			do
			{
				d=getch();
			}while(d!=224&&d!=13);
			if(d==224)
				switch(getch())
				{
					case 75:case 80:a=(a+2)%3;break;
					case 77:case 72:a=(a+1)%3;break;
				}
		}while(d!=13);
		b=rand()%3;
		draw(a,b);
	 	if(a==b) x=2;
		else if((a==0&&b==1)||(a==1&&b==2)||(a==2&&b==0)) x=1;		
		else x=0;
		Sleep(1000);		
	}while(x==2);	
	if(x==1)
		printf("\t\t\t\t--BAN RUT TRUOC--\n");
	else
		printf("\t\t\t\t--MAY RUT TRUOC--\n");
	printf("%55s","NHAN ENTER DE TIEP TUC...");
	while(getch()!=13);
	return x;
}

void huongdan()
{
	system("cls");
	printf("\n\n%64s","---------------HUONG DAN TRO TROI---------------\n\n\n");
	puts("* Co 15 que diem duoc xep vao` 3 o voi' so luong moi o");
	puts("  la 3 - 5 - 7.\n\n");
	puts("* 2 nguoi choi se~ luon phien nhau rut' diem.\n\n");
	puts("* Moi lan` chi? dc rut' 1 luong diem o? duy nhat' ");
	puts("  1 trong 3 o.\n\n");
	puts("* Thang` nao` phai? rut' que diem cuoi cung` la` THUA :v!!");
	puts("\n\n\t\t\tBam phim ENTER de quay lai MENU.");
	while(getch()!=13);
}

void thongtin()
{
	system("cls");
	printf("\n\n%64s","---------------THONG TIN SAN PHAM---------------\n\n\n");
	puts("*\t Ngay ra mat:\tDeo' Nho'\n");
	puts("*\t Tac gia:\t Nguyen K Hung\n");
	puts("*\t The loai: GAME HAI NAO~!!\n");
	puts("*\t Cau hinh yeu cau:\tDeo' Quan Tam\n\n\n");
	puts("##CHU Y:BANG DIEM se~ bi reset sau khi tat' chg trinh`:D");
	puts("\n\n\t\t\tBam phim ENTER de quay lai MENU.");
	while(getch()!=13);
}

void menu(int a)
{
	system("cls");
	char c[5][10]={" BAT DAU ","HUONG DAN","THONG TIN"," DIEM SO ","  THOAT  "};
	printf("%64s","#--------------------------------------------#\n");
	printf("%64s","|          *                     *           |\n");
	printf("%64s","|         *                     * *          |\n");
	printf("%64s","| @@@@  @   @ @@@@@    @@@@  @ @@@@@ @     @ |\n");
	printf("%64s","| @   @ @   @   @      @   @ @ @     @@   @@ |\n");
	printf("%64s","| @@@@  @   @   @      @   @ @ @@@@@ @ @ @ @ |\n");
	printf("%64s","| @  @  @   @   @      @   @ @ @     @  @  @ |\n");
	printf("%64s","| @   @  @@@    @      @@@@  @ @@@@@ @     @ |\n");
	printf("%65s","#--------------------------------------------#\n\n");
	for(i=0;i<15;i++)
		if((i-1)%3==0)
			if(a*3+1==i)
				printf("%20s%25s\n","-->>",c[(i-1)/3]);
			else printf("%45s\n",c[(i-1)/3]);
		else if(a*3==i||a*3+2==i)printf("%56s\n","_/\\_*---------------------*_/\\_");
		else puts(" ");
}

main()
{
	int c,t,x=0,y=0,a=0;
	srand(time(NULL));
	do
	{
		do{
		menu(a);
		do 
			c=getch();
		while(c!=13&&c!=224);
		if(c==224)
			switch(getch())
			{
				case 80:case 77:a=++a%5;break;
				case 72:case 75:a=(a+4)%5;break;
			}}while(c!=13);
			switch(a)
			{
				case 0:x+=(1-game(oantuti()));y++;break;
				case 1:huongdan();break;
				case 2:thongtin();break;
				case 3:score(x,y);break;
				case 4:exit;
			}
	}while(a!=4);
}