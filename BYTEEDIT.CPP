//NOTEPOINT TEXT EDITOR
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<dos.h>
char arr[10000];
int pos(char str[],char ch)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==ch)
			return i+1;
		else
			continue;
	}
}
int syntax(char com[])
{
	int num;
	num=pos(com,')');
	if(com[num]=='\0')
		return 1;
	else
		return -1;
}
int strchk1()
{
	int sum;
	int num;
	num=pos(arr,'\n');
	sum=80-num;
	return sum;
}
void code1(int code,int &x,int &y)
{
	if(code==2)
	{
		gotoxy(x,y+1);
		y++;
	}
	else
	if(code==8)
	{
		gotoxy(x,y-1);
		y--;
	}
	else
	if(code==4)
	{
		if(x==1)
		{
			x=80;
			y--;
			gotoxy(x,y);
		}
		else
		{
			gotoxy(x-1,y);
			x--;
		}
	}
	else
	if(code==6)
	{
		if(x==80)
		{
			x=1;
			y++;
			gotoxy(x,y);
		}
		else
		{
			gotoxy(x+1,y);
			x++;
		}
	}
}
int detect(int x,int y)
{
	int num;
	num=strchk1();
	if(strlen(arr)+1+num>=x+(80*(y-1)))
		return 1;
	else
		return 0;
}
int color(char str[])
{
	if(strcmp(str,"BLACK")==0)
		return 0;
	else
	if(strcmp(str,"BLUE")==0)
		return 1;
	else
	if(strcmp(str,"GREEN")==0)
		return 2;
	else
	if(strcmp(str,"CYAN")==0)
		return 3;
	else
	if(strcmp(str,"RED")==0)
		return 4;
	else
	if(strcmp(str,"MAGENTA")==0)
		return 5;
	else
	if(strcmp(str,"BROWN")==0)
		return 6;
	else
	if(strcmp(str,"LIGHTGREY")==0)
		return 7;
	else
	if(strcmp(str,"DARKGREY")==0)
		return 8;
	else
	if(strcmp(str,"LIGHTBLUE")==0)
		return 9;
	else
	if(strcmp(str,"LIGHTGREEN")==0)
		return 10;
	else
	if(strcmp(str,"LIGHTCYAN")==0)
		return 11;
	else
	if(strcmp(str,"LIGHTRED")==0)
		return 12;
	else
	if(strcmp(str,"LIGHTMAGENTA")==0)
		return 13;
	else
	if(strcmp(str,"YELLOW")==0)
		return 14;
	else
	if(strcmp(str,"WHITE")==0)
		return 15;
	else
	if(strcmp(str,"BLINK")==0)
		return 128;
	else
		return -1;
}
void push(int n,int len)
{
	int i;
	len--;
	for(i=strlen(arr)-1;i>=len;i--)
		arr[i+n]=arr[i];
	strcat(arr,'\0');
}
void pull(int n,int len)
{
	int i,c;
	len--;
	for(i=len;arr[i]!='\0';i++)
		arr[i-n]=arr[i];
	c=strlen(arr);
	arr[c-1]='\0';
}
void upper(char str [])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(islower(str[i])!=0)
			str[i]=toupper(str[i]);
	}
}
void help(char str[])
{
	upper(str);
	if(strcmp(str,"OPEN")==0)
	{
		cout<<"\n\tOPENS AN EXISTING FILE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>OPEN(FILE_NAME)\n";
	}
	else
	if(strcmp(str,"CLOSE")==0)
	{
		cout<<"\n\tCLOSES AN OPENED FILE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>CLOSE()\n";
	}
	else
	if(strcmp(str,"NEW")==0)
	{
		cout<<"\n\tCREATES A NEW FILE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>NEW(FILE_NAME)\n";
	}
	else
	if(strcmp(str,"SAVE AS")==0)
	{
		cout<<"\n\tSAVES THE COPY OF THE FILE WITH ANOTHER NAME\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>SAVE AS(FILE_NAME)\n";
	}
	else
	if(strcmp(str,"CLS")==0)
	{
		cout<<"\n\tCLEARS THE SCREEN\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>CLS()\n";
	}
	else
	if(strcmp(str,"CLSF")==0)
	{
		cout<<"\n\tCLEARS THE CONTENT OF FILE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>CLSF()\n";
	}
	else
	if(strcmp(str,"DELETE")==0)
	{
		cout<<"\n\tDELETES THE FILE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>DELETE(FILE_NAME)\n";
	}
	else
	if(strcmp(str,"WC")==0)
	{
		cout<<"\n\tCOUNTS THE NUMBER OF CHARACTERS,WORDS AND LINES\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>WC()\n";
	}
	else
	if(strcmp(str,"EDIT")==0)
	{
		cout<<"\n\tOPENS THE FILE IN EDIT MODE\n\n";
		cout<<"\n\tUSE ARROW KEYS TO MOVE THE CURSOR.\n\n";
		cout<<"\n\tUSE ESC TO EXIT THE EDIT MODE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>EDIT()\n";
	}
	else
	if(strcmp(str,"DISPLAY")==0)
	{
		cout<<"\n\tDISPLAYS THE FILE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>DISPLAY()\n";
	}
	else
	if(strcmp(str,"WRITE")==0)
	{
		cout<<"\n\tWRITES IN THE FILE\n\n";
		cout<<"\n\tUSE ESC TO EXIT THE EDIT MODE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>WRITE()\n";
	}
	else
	if(strcmp(str,"EXIT")==0)
	{
		cout<<"\n\tEXITS THE APPLICATION\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>EXIT()\n";
	}
	else
	if(strcmp(str,"TEXTCOLOR")==0)
	{
		cout<<"\n\tCHANGES THE TEXTCOLOR\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>TEXTCOLOR(COLOR_NAME)\n";
	}
	else
	if(strcmp(str,"FINDREP")==0)
	{
		cout<<"\n\tFINDS THE WORD AND REPLACES IT\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>FINDREP()\n";
	}
	else
	if(strcmp(str,"RENAME")==0)
	{
		cout<<"\n\tRENAMES THE EXISTING FILE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>RENAME()\n";
	}
	else
	if(strcmp(str,"TIME")==0)
	{
		cout<<"\n\tDISPLAYS THE CURRENT SYSTEM TIME\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>TIME()\n";
	}
	else
	if(strcmp(str,"DATE")==0)
	{
		cout<<"\n\tDISPLAYS THE CURRENT SYSTEM DATE\n\n";
		cout<<"\tSYNTAX: \n";
		cout<<"\t\t>>>DATE()\n";
	}
}
int filechk(char str [])
{
	fstream fp;
	fp.open(str,ios::in|ios::out|ios::nocreate);
	if(fp)
		return 1;
	else
		return 0;
}
int empty(char str[])
{
	int n,t;
	fstream fp;
	fp.open(str,ios::in|ios::out|ios::nocreate);
	fp.seekg(0,ios::beg);
	n=fp.tellg();
	fp.seekg(0,ios::end);
	t=fp.tellg();
	fp.close();
	if(n==t)
		return 1;
	else
		return 0;
}
int strchk(char str1[],char str2[],int num)
{
	int i,cnt=0;
	for(i=0;i<=num-1;i++)
	{
		if(str1[i]==str2[i])
		{
			cnt++;
		}
		else
			break;
	}
	if(cnt==num)
	{
		return 1;
	}
	else
		return 0;
}
void main()
{
	clrscr();
	fstream fp;
	char str[50],str2[50],str1[50],op,*record[20],ch,ch1;
	int n=5,i,t,cnt=0,len,rec=0;
	cout<<"\t\t\t\tNOTEPOINT\n\n";
	while(n==5)
	{
		cout<<"\n\n>>>";
		str[0]='\0';
		while(!kbhit())
		{
			ch=getche();
			if(ch==13 && str[0]=='\0')
				cout<<"\n\n>>>";
			else
			if(ch==13)
			{
				str[cnt]='\0';
				if(syntax(str)==-1)
				{
					cout<<"\n\n\t\t>>SYNTAX ERROR";
					cout<<"\n\n>>>";
					str[0]='\0';
					cnt=0;
				}
				else
					break;
			}
			else
			if(ch==8)
			{
				if(cnt==0)
				{
					gotoxy(4,wherey());
					continue;
				}
				else
				{
					str[cnt-1]='\0';
					cnt--;
					clreol();
				}
			}
			else
			{
				str[cnt]=ch;
				cnt++;
			}
		}
		upper(str);
		cnt=0;
		if(strchk(str,"OPEN(",5)>0)
		{
			char ch;
			for(i=5;str[i]!=')';i++)
			{
				str1[cnt]=str[i];
				cnt++;
			}
			str1[cnt]='\0';
			cnt=0;
			if(filechk(str1)==1)
			{
				fp.open(str1,ios::in|ios::out|ios::app);
				fp.get(ch);
				while(!fp.eof())
				{
					arr[cnt]=ch;
					fp.get(ch);
					cnt++;
				}
				arr[cnt]='\0';
				cnt=0;
				fp.close();
				fp.open(str1,ios::in|ios::out|ios::app);
			}
			else
				cout<<"\n\t\t>>FILE DOES NOT EXIST\n";
		}
		else
		if(strchk(str,"TIME()",6)>0)
		{
			struct  time ti;
			gettime(&ti);
			cout<<endl<<endl;
			printf("THE CURRENT TIME IS: %2d:%02d:%02d.%02d\n",
			ti.ti_hour, ti.ti_min, ti.ti_sec, ti.ti_hund);
		}
		else
		if(strchk(str,"DATE()",6)>0)
		{
			struct date d1;
			getdate(&d1);
			cout<<endl<<endl;
			printf("THE CURRENT DATE IS: %d/%d/%d", d1.da_day,d1.da_mon,d1.da_year);

		}
		else
		if(strchk(str,"CLOSE()",7)>0)
		{
			fp.close();
			arr[0]='\0';
		}
		else
		if(strchk(str,"NEW(",4)>0)
		{
			for(i=4;str[i]!=')';i++)
			{
				str1[cnt]=str[i];
				cnt++;
			}
			str1[cnt]='\0';
			cnt=0;
			if(filechk(str1)==1)
			{
				cout<<"\n\t\t>>FILE ALREADY EXISTS\n";
				cout<<"\n\t\t>>WANT TO REPLACE FILE?Y/N";
				cin>>op;
				if(op=='Y' && op=='y')
				{
					remove(str1);
					fp.open(str1,ios::in|ios::out|ios::app);
				}
			}
			else
				fp.open(str1,ios::in|ios::app|ios::out);
		}
		else
		if(strchk(str,"DISPLAY()",9)>0)
		{
			char let;
			if(empty(str1)==0)
			{
				fp.get(let);
				cout<<endl<<endl;
				while(!fp.eof())
				{

					cout<<let;
					fp.get(let);
				}
				cout<<let<<endl;
			}
			else
				cout<<"\n\t\t>>FILE IS EMPTY!!!\n";
			fp.close();
			fp.open(str1,ios::in|ios::out|ios::app);
		}
		else
		if(strchk(str,"CLSF()",6)>0)
		{
			fp.close();
			fp.open(str1,ios::in|ios::out|ios::trunc);
			fp.close();
			fp.open(str1,ios::in|ios::out);
		}
		else
		if(strchk(str,"WRITE()",7)>0)
		{
			char ch9;
			int i=0;
			cout<<endl<<endl;
			while(1)
			{
				ch9=getch();
				if(ch9==27)
					break;
				else
				if(ch9==8)
				{
					clreol();
					arr[i-1]='\0';
					i--;
				}
				else
				if(ch9==13)
				{
					cout<<endl<<endl;
					ch9='\n';
					arr[i]='\n';
					i++;
					fp.put(ch9);
				}
				else
				{
					fp.put(ch9);
					arr[i]=ch9;
					i++;
					cout<<ch9;
				}
			}
			fp.close();
			fp.open(str1,ios::in|ios::app|ios::out);
		}

		else
		if(strchk(str,"FINDREP()",9)>0)
		{
			fstream fp1;
			int num=0;
			char wrd9[20],orig[40],rep[40];
			cout<<"\n\t\t\t>>ENTER WORD TO BE FOUND: ";
			cin>>orig;
			cout<<"\n\t\t\t>>ENTER WORD TO BE REPLACED WITH: ";
			cin>>rep;
			fp1.open("temp.txt",ios::in|ios::out|ios::app);
			while(!fp.eof())
			{
				fp>>wrd9;
				if(strcmp(wrd9,orig)==0)
				{
					num++;
					fp1<<rep;
					fp1<<" ";
				}
				else
				{
					fp1<<wrd9;
					fp1<<" ";
				}
			}
			strcat(orig,".");
			strcat(rep,".");
			while(!fp.eof())
			{
				fp>>wrd9;
				if(strcmp(wrd9,orig)==0)
				{
					num++;
					fp1<<rep;
					fp1<<" ";
				}
				else
				{
					fp1<<wrd9;
					fp1<<" ";
				}
			}
			if(strcmp(wrd9,orig)==0)
				{
					num++;
					fp1<<rep;
					fp1<<" ";
				}
				else
				{
					fp1<<wrd9;
					fp1<<" ";
				}
			cout<<"\t\t\t>>"<<num<<" WORDS REPLACED";
			fp.close();
			fp1.close();
			remove(str1);
			rename("temp.txt",str1);
			fp.open(str1,ios::in|ios::out|ios::app);
		}
		else
		if(strchk(str,"EDIT()",6)>0)
		{
			char key;
			int x,y,code;
			const int num=80;
			clrscr();
			cout<<"\t\t\t\tNOTEPOINT\n\n";
			cout<<"\n\n>>>EDIT()\n\n";
			cout<<arr;
			x=wherex();
			y=wherey();
			while(1)
			{
				while(!kbhit()){}
				key=getch();
				if(key==8)
				{
					if(detect(x,y-6)==1)
					{
						clrscr();
						cout<<"\t\t\t\t\tNOTEPOINT\n\n";
						cout<<"\n\n>>>EDIT()\n\n";
						pull(1,x+(num*(y-6-1)));
						cout<<arr;
						x--;
						if(x==0)
						{
							x=num;
							y--;
							gotoxy(x,y);
						}
						else
							gotoxy(x,y);
					}
					else
					{
						if(x==1)
						{
							x=num;
							y--;
							gotoxy(x,y);
						}
						else
						{

							x--;
							gotoxy(x,y);
						}
					}
				}
				else
				if(key==27)
					break;
				else
				if(key==0 || key==-32)
				{
					key=getch();
					if(key==80)
						code1(2,x,y);
					else
					if(key==72)
						code1(8,x,y);
					else
					if(key==75)
						code1(4,x,y);
					else
					if(key==77)
						code1(6,x,y);
				}
				else
				if(key==13)
				{
					x=wherex();
					cout<<endl;
					arr[x]='\n';
				}
				else
				{
					clrscr();
					cout<<"\t\t\t\tNOTEPOINT\n\n";
					cout<<"\n\n>>>EDIT()\n\n";
					push(1,x+(num*(y-6-1)));
					arr[x+(num*(y-6-1))-1]=key;
					cout<<arr;
					x++;
					if(x==num+1)
					{
						x=1;
						y++;
						gotoxy(x,y);
					}
					else
						gotoxy(x,y);
				}
			}
			fp.close();
			remove(str1);
			fp.open(str1,ios::in|ios::out|ios::app);
			for(i=0;arr[i]!='\0';i++)
				fp.put(arr[i]);
			fp.close();
			fp.open(str1,ios::in|ios::out|ios::app);
		}
		else
		if(strchk(str,"TEXTCOLOR(",10)>0)
		{
			int l;
			for(i=10;str[i]!=')';i++)
			{
				str1[cnt]=str[i];
				cnt++;
			}
			str1[cnt]='\0';
			cnt=0;
			l=color(str1);
			if(l==-1)
				cout<<"\n\n\t\t>>COLOR DOES NOT EXIST";
			else
			{
				textcolor(l);
				clrscr();
				cout<<"\t\t\t\tNOTEPOINT\n\n";
			}
		}
		else
		if(strchk(str,"SAVEAS()",8)>0)
		{
			fstream fp1;
			char ch,str7[50];
			cout<<"\n\t\t>>ENTER NEW FILE NAME: ";
			cin>>str7;
			fp1.open(str7,ios::in|ios::out);
			while(!fp.eof())
			{
				fp.get(ch);
				fp1<<ch;
			}
			fp1.close();
		}
		else
		if(strchk(str,"WC()",4)>0)
		{
			int cnt1=1,cnt2=0,cnt3=0;
			char wrd3[20],ch6;
			fp.close();
			fp.open(str1,ios::in|ios::out);
			fp>>wrd3;
			while(!fp.eof())
			{
				cnt1++;
				fp>>wrd3;
			}
			fp.close();
			fp.open(str1,ios::in|ios::out);
			fp>>ch6;
			while(!fp.eof())
			{
				if(ch6=='.')
					cnt2++;
				cnt3++;
				fp>>ch6;
			}
			cout<<endl;
			cout<<"\t\t>>NUMBER OF WORDS: "<<cnt1<<endl<<endl;
			cout<<"\t\t>>NUMBER OF LINES: "<<cnt2<<endl<<endl;
			cout<<"\t\t>>NUMBER OF CHARACTERS: "<<cnt3<<endl;
			fp.close();
			fp.open(str1,ios::in|ios::out);
		}
		else
		if(strchk(str,"DELETE(",7)>0)
		{
			fp.close();
			for(i=7;str[i]!=')';i++)
			{
				str1[cnt]=str[i];
				cnt++;
			}
			str1[cnt]='\0';
			cnt=0;
			if(filechk(str1)==1)
				remove(str1);
			else
				cout<<"\n\t\t>>FILE DOES NOT EXIST\n";
		}
		else
		if(strchk(str,"CLS()",5)>0)
		{
			clrscr();
			cout<<"\t\t\t\tNOTEPOINT\n\n";
		}
		else
		if(strchk(str,"EXIT()",6)>0)
		{
			fp.close();
			exit(0);
		}
		else
		if(strchk(str,"RENAME()",8)>0)
		{
			fp.close();
			char str8[100];
			cout<<"\n\t\t>>ENTER NEW FILE NAME: ";
			cin>>str8;
			rename(str1,str8);
			fp.open(str8,ios::in|ios::out|ios::app);
		}
		else
		if(strchk(str,"HELP()",6)>0)
		{
			cout<<"\n\n\tOPEN()";
			cout<<"\t\tNEW()";
			cout<<"\t\tCLOSE()\n\n";
			cout<<"\tSAVE AS()";
			cout<<"\tCLS()";
			cout<<"\t\tCLSF()\n\n";
			cout<<"\tDELETE()";
			cout<<"\tWC()";
			cout<<"\t\tFINDREP()\n\n";
			cout<<"\tEDIT()";
			cout<<"\t\tDISPLAY()";
			cout<<"\tWRITE()\n\n";
			cout<<"\tEXIT()";
			cout<<"\t\tRENAME()";
			cout<<"\tTEXTCOLOR()\n\n";
			cout<<"\tTIME()";
			cout<<"\t\tDATE()\n\n";
			cout<<"\tFOR HELP ON A PARTICULAR FUNCTION TYPE HELP(FUNCTION_NAME)\n";
		}
		else
		if(strchk(str,"HELP(",5)>0)
		{
			char str6[50];
			for(i=5;str[i]!=')';i++)
			{
				str6[cnt]=str[i];
				cnt++;
			}
			str6[cnt]='\0';
			cnt=0;
			cout<<endl;
			help(str6);
		}
		else
		{
			cout<<"\n\n\t\t>>FUNCTION NOT IDENTIFIED";
			rec--;
		}

	}
	getch();
}