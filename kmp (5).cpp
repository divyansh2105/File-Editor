using namespace std;
#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<limits>
float array[26]={0,7.11,11.80,20.17,24.85,28.54,31.55,34.49,38.33,42.05,42.74,43.68,46.34,51.61,54.46,57.78,68.08,68.57,72.75,83.35,88.82,95.79,97.23,98.94,99.1,99.38};
char ar[10][30];
int pcount=0;
char history[20][30];
void predictive(char pat[], int l)
{
    ifstream in4("wordsnew.txt");
    	 long int middle;
    	 char str[255];
    	 char str5[256];
    	 int cc=0;
    	 int first=pat[0]-97;
in4.seekg(11*array[first]*3700);
if(first!=0){in4>>str5;
in4>>str5;}
    	 while(cc<10 && !in4.eof())
         {int aa=1,count=0;
           in4>>str;

             if(strcmpi(str,pat)==0)
		{
		    strcpy(ar[cc],str);
		    cout<<cc<<".  "<<str<<endl;cc++;
		}
		else
        {
            while(count<l)
            {
                if(str[count]!=pat[count])
                {
                    aa=0;
                    break;
                }
                count++;
            }
            if(aa==1)
            {
                strcpy(ar[cc],str);
                cout<<cc<<".  "<<str<<endl;cc++;
            }
         }
    }

  in4.close();
}
void predict()
{

    char c='\0';
    char str[100]={'\0'};
    char fin[30];
    cout<<endl<<endl<<"enter word you want to search: ";
    while(c!=' ' || c=='/')
    {
        char ch='\0';
        c=getch();
        int ic=c;
        if((ic<48 || ic>57) && ic!=8 && ic!=47)
        {
        char r[2]={c,'\0'};
        strcat(str,r);
        cout<<endl;
        system("cls");
        cout<<str<<endl<<endl;
        cout<<"Search suggestions"<<endl;
        predictive(str,strlen(str));
        cout<<endl<<endl<<"search history "<<endl;
        if(pcount==0)
        {
            cout<<"no searches yet ";
        }
        else
        {
        for(int i=0;i<pcount;i++)
        {
            cout<<i<<". "<<history[i]<<"  ";
        }
        }
        cout<<endl<<endl<<"enter index no. to search for respective string, press '/' to select and ' ' to cancel";
        }
        else if((ic>=48 && ic<=57) && ic!=8 && ic!=47)
        {int x=c-'0';

            strcpy(str,ar[x]);
            cout<<endl;
        system("cls");
        cout<<str<<endl<<endl;
        cout<<"Search suggestions"<<endl;
        predictive(str,strlen(str));
        cout<<endl<<endl<<"search history "<<endl;
        if(pcount==0)
        {
            cout<<"no searches yet ";
        }
        else
        {
        for(int i=0;i<pcount;i++)
        {
            cout<<i<<". "<<history[i]<<"  ";
        }
        }
        cout<<endl<<endl<<"enter index no. to search for respective string, press '/' to select and ' ' to cancel";
        }
        else if(ic==8 && ic!=47)
        {
            str[strlen(str)-1]='\0';
            cout<<endl;
        system("cls");
        cout<<str<<endl<<endl;
        cout<<"Search suggestions"<<endl;
        predictive(str,strlen(str));
        cout<<endl<<endl<<"search history "<<endl;
        if(pcount==0)
        {
            cout<<"no searches yet ";
        }
        else
        {
        for(int i=0;i<pcount;i++)
        {
            cout<<i<<". "<<history[i]<<"  ";
        }
        }
        cout<<endl<<endl<<"enter index no. to search for respective string, press '/' to select and ' ' to cancel";
        }
        else if(ic==47)
        {
            strcpy(fin,str);
            cout<<endl<<"word selected->";
            cout<<fin<<endl;
            strcpy(history[pcount],fin);
            pcount++;
            break;
        }
    }
}
void createfile()
{
    char fname[30];
    char line[1000];
    cout<<"Enter name of the file:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(fname,30);
    fstream f;
    f.open(strcat(fname,".txt"),ios_base::out);
    cout<<"Enter text,enter # to exit"<<endl;
    do
    {
        cin.getline(line,1000);
        if(line[0]=='#')
            break;
        f<<line<<endl;

    }while(line[0]!='#');
    f.close();
}
void display(char fname[30])
{
    ifstream f;
    char line[1000];
    int l=1;
    f.open(fname,ios_base::in);
    while(!f.eof())
    {
        f.getline(line,1000);
        //f>>line;
        cout<<l<<": "<<line<<endl;
        l++;
    }
    f.close();
}
void editfile()
{
    char fname[30];
    int ln,lcount=1;
    char line[1000];
    char nline[1000];
    cout<<"Enter name of the file:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(fname,30);
    display(fname);
    cout<<"Enter the line number to be edited :";
    cin>>ln;
    cout<<"Enter line to replace old line:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(nline,1000);
    fstream f1,f2;
    f1.open(fname,ios_base::in);
    f2.open("temp.txt",ios_base::out);
    if(!f1.is_open())
    {
        cout<<"error";
        return;
    }
    while(!f1.eof())
    {
        f1.getline(line,1000);
        if(lcount==ln)
        {
            f2<<nline<<endl;
        }
        else
        {
            f2<<line<<endl;
        }
        lcount++;
    }
    f1.close();
    f2.close();
    remove(fname);
    rename("temp.txt",fname);
}
void deletefile()
{
    char fname[30];
    cout<<"Enter name of the file to be deleted:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(fname,30);
    remove(strcat(fname,".txt"));
}
void findandreplace()
{
    char srcword[20];
    char repword[20];
    char fname[30];
    char line[1000];
    char word[30];
    cout<<"Enter the name of the file:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(fname,30);
    fstream f,f1;
    f.open(fname,ios_base::in);
    f1.open("temp.txt",ios_base::out);
    display(fname);
    cout<<"Enter the word :"<<endl;
    cin>>srcword;
    cout<<"Enter the replacement word:"<<endl;
    cin>>repword;
    while(!f.eof())
    {
        f.getline(line,1000);
        char *pos = strstr(line,srcword);
        if (pos != NULL)
        {
         size_t newlen = strlen(line) - strlen(srcword) + strlen(repword);
         char new_sentence[newlen + 1];
         while(pos!=NULL)
         {
         memcpy(new_sentence, line, pos - line);
         memcpy(new_sentence + (pos - line), repword, strlen(repword));
         strcpy(new_sentence + (pos - line) + strlen(repword), pos + strlen(srcword));
         strcpy(line,new_sentence);
         pos = strstr(line,srcword);
         }
         f1<<new_sentence<<endl;
         }
         else
         {
            f1<<line<<endl;
         }
    }
    f.close();
    f1.close();
    remove(fname);
    rename("temp.txt",fname);
}

void computeLPSArray(char *pat, int M, int *lps);
int count=0;
int KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int lps[M];
	computeLPSArray(pat, M, lps);

	int i = 0;
	int j = 0;
	int flag=0;
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{

                flag=1;
                    cout<<txt<<"\n";return 1;
			j = lps[j-1];
		}
		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
	return flag;
}

void computeLPSArray(char *pat, int M, int *lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
        {
			if (len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int binarys(int first, int last, char pat[])
{
    if(strcmpi(pat,"a")==0)
    {
        return 1;
    }
        ifstream in4("wordsnew.txt");
    	 long int middle;
    	 char str[255];
    while(last-first>1)
	{
		middle=((last+first)/2);
		in4.seekg(middle);
		in4>>str;
		in4>>str;
		if(strcmpi(str,pat)==0)
		{
		    return 1;
		}
		else if(strcmpi(str,pat)<0)
		first=middle;
		else
		last=middle;

  }
  in4.close();
  return 0;
}
void spellcheck()
{
    cout<<"Enter file name:";
    char fname[30];
    cin>>fname;
        ifstream in2(fname);

  if(!in2) {
    cout << "Cannot open input file.\n";
    return;
  }


long int f=0,l=0;
while(in2)
{
    char pat[255];
in2>>pat;
for(int i = 0; i < strlen(pat); ++i)
    {
        if (!((pat[i] >= 'a' && pat[i]<='z') || (pat[i] >= 'A' && pat[i]<='Z')))
        {
            pat[i] = '\0';
        }
    }
    ifstream in("wordsnew.txt");
  if(!in) {
    cout << "Cannot open input file.\n";
    return;
  }
int flg=0,count=0,areequal=0;
  in.seekg(0,ios::beg);
	long int first=in.tellg();
	in.seekg(0,ios::end);
	long int last=in.tellg();
	in.seekg(0,ios::beg);
	 char str[255],str2[255];
	 areequal=binarys(first,last,pat);

  if((first+last)/2==1)
  areequal=1;
  if(areequal==0){
  ifstream in3("wordsnew.txt");
  cout<<pat;
    cout<<"->not found\nSuggested matches\n";
    char str5[256];
        	 int first=pat[0]-97;
in3.seekg(11*array[first]*3700);
if(first!=0){in3>>str5;
in3>>str5;}
  while(in3) {
         char str[255];
    in3.getline(str, 255);
    if(in3)
    {
         if(count<4)
         {
         flg=KMPSearch(pat, str);
         if(flg==1)
         {  count++;}
          if(flg==0)
          {
          }
       }

    }
        else if(count>=4)
        {
            break;
        }
  }
if(count<4)
{
  ifstream in5("wordsnew.txt");
      char pathalf[256];
          int halflen=strlen(pat);
           for(int j=0;j<=halflen/2;j++)
    {
        pathalf[j]=pat[j];
    }
    pathalf[(halflen/2)+1]='\0';
    in5.seekg(11*array[first]*3700);
if(first!=0){in5>>str5;
in5>>str5;}
  while(in5) {
         char str[255];
    in5.getline(str, 255);
    if(in5)
    {
         if(count<4)
         {
          int len=strlen(pat);
         flg=KMPSearch(pathalf, str);
         if(flg==1)
         {  count++;}
       }

    }
        else if(count>=4)
        {
            break;
        }

  }

}
  if(flg==0)
  {
      cout<<"none ";

  }
  in3.close();
  cout<<endl;
  }

}
in2.close();
}
int main()
{
    int d;char ch[100];
    x:cout<<"Enter choice\n1:Create file\n2:Edit file\n3:Delete file\n4:Display file\n5:Find and Replace"<<endl;
    cout<<"6:Enter word to search\n7:Spell check\n8:Exit\n";
    cin>>d;
    switch(d)
    {
        case 1:createfile();break;
        case 2:editfile();break;
        case 3:deletefile();break;
        case 4:cout<<"Enter file name";cin>>ch;display(ch);break;
        case 5:findandreplace();break;
        case 6:predict();break;
        case 7:spellcheck();break;
        case 8:return 0;
    }
    cout<<"Enter your choice or press 8 to exit\n"<<endl;
    goto x;
	return 0;
}

