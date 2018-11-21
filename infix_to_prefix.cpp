
#include<iostream>
#include<stack_array_str.h>
#include<string.h>
using namespace std;
	void accept(char *,char *);
	void display(char *);
	void convert(char *);
int main()
{

	int c,arrsize=20;
	char arrstring[arrsize],copyarrstring[arrsize];
	do
	{
		cout<<"\n\n\n enter your choice \n 1.Accept expression \n 2.Display infix expresion \n 3.Display prefix expression \n 4.convert infix to postfix. \n 0.exit.";
		cin>>c;
		switch(c)
		{
			case 1:{
				accept(arrstring,copyarrstring);
				break;
				}
			case 2:{
			    cout<<"\n The infix expression is:";
				display(arrstring);
				break;
				}
			case 3:{
			    if(strcmp(arrstring,copyarrstring)==0)
                {
                    cout<<"\n not coverted to prefix!!! \n Select option 4 to convert...";
                }
                else
                {
                    cout<<"\n The expression is:";
                    display(copyarrstring);
                }
				break;
				}
            case 4:{
				convert(copyarrstring);
				break;
				}

			 default:{
					cout<<"\n wrong input entered!!!";
					break;
				      }
		}
	    cout<<"\n___________________________________________________\n";
	}while(c!=0 && c<5 && c>0);
	return 0;
}

	void accept(char *arrstring,char *copyarrstring)
	{
		cout<<"\n Enter the infix expression:";
        cin>>arrstring;
        strcpy(copyarrstring,arrstring);
        cout<<"\n The infix expression is:";
        display(arrstring);
	}

	void display(char *arrstring)
		{
			cout<<arrstring;
		}

void convert(char *copyarrstring){
    char symbolstack[20],outputstack[20];
    int i=0,topsymbolstack=-1,topoutputstack=-1;
    while(copyarrstring[i]!='\0')
    {
        if(isempty(topoutputstack)==1)
                    {
                        cout<<"\n output:";
                        cout<<"Stack underflow!!!";
                    }
                    else
                    {
                        cout<<"\n output:";
                       display(outputstack);
                    }
                    if(isempty(topsymbolstack)==1)
                    {
                       cout<<"\n symbol:";
                        cout<<"Stack underflow!!!";
                    }
                    else
                    {
                         cout<<"\n symbol:";
                         display(symbolstack);
                    }
        cout<<"\n i:"<<i;
       if((int)copyarrstring[i]==')'||(int)copyarrstring[i]==']'||(int)copyarrstring[i]=='}')
        {
                 if(isempty(topsymbolstack)==1&&i==0)
                {
                    cout<<"\n error!!! Wrong input";
                    break;
                }else
                {
                   if((int)copyarrstring[i]==')')
                    {
                        cout<<"\n ''''''"<<topoutputstack;
                        char popped,tempstack[20];
                        int toptempstack=-1;
                        while((int)outputstack[topoutputstack]!='(')
                        {
                            cout<<"\n outputstack top"<<outputstack[topoutputstack];
                            popped=pop(outputstack,topoutputstack);
                            cout<<"\n popped"<<popped;
                            topoutputstack--;
                            cout<<"\n outputstack top after popping"<<outputstack[topoutputstack];
                            toptempstack=push(tempstack,toptempstack,popped);
                        }
                        cout<<"\n after while:"<<outputstack[topoutputstack];
                        cout<<"\n symbolstack top"<<symbolstack[topsymbolstack];
                        popped=pop(symbolstack,topsymbolstack);
                        topsymbolstack--;
                        topoutputstack--;//to over write the bracket position
                        cout<<"\ntopoutpstack:"<<topoutputstack;
                        topoutputstack=push(outputstack,topoutputstack,popped);
                        cout<<"\n outputstack top after symb is pushed"<<outputstack[0]<<outputstack[topoutputstack];
                        cout<<"\n tempsta top"<<toptempstack;
                        for(int j=toptempstack;j>=0;j--)
                        {
                            popped=pop(tempstack,j);
                            toptempstack--;
                            topoutputstack=push(outputstack,topoutputstack,popped);
                        }
                        outputstack[topoutputstack+1]='\0';
                    }
                    else
                    {
                        if((int)copyarrstring[i]==']'||(int)copyarrstring[i]=='}')
                        {
                            char popped;
                             while((int)symbolstack[topsymbolstack]!=(int)copyarrstring[i]-2)
                            {

                                popped=pop(symbolstack,topsymbolstack);
                                topsymbolstack--;
                                topoutputstack=push(outputstack,topoutputstack,popped);
                                outputstack[topoutputstack+1]='\0';
                                }
                                popped=pop(symbolstack,topsymbolstack);
                                topsymbolstack--;
                            }
                      }


                    }
                    i++;
        }
        else
        {
            if((int)copyarrstring[i]>64&&(int)copyarrstring[i]<91||(int)copyarrstring[i]>96&&(int)copyarrstring[i]<123||(int)copyarrstring[i]=='('||(int)copyarrstring[i]=='['||(int)copyarrstring[i]=='{')
        {
            topoutputstack=push(outputstack,topoutputstack,copyarrstring[i++]);
            outputstack[topoutputstack+1]='\0';

        }else
        {
            if((int)copyarrstring[i]=='*'||(int)copyarrstring[i]=='/'||(int)copyarrstring[i]=='+'||(int)copyarrstring[i]=='-')
            {
                topsymbolstack=push(symbolstack,topsymbolstack,copyarrstring[i++]);
                symbolstack[topsymbolstack+1]='\0';
            }
            else
            {
                    cout<<"\n wrong input!!!";
                    break;
            }

        }

    }
        }
strcpy(copyarrstring,outputstack);

}
