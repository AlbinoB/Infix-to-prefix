
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
                        char popped,tempstack[20];
                        int toptempstack=-1;
                        while((int)outputstack[topoutputstack]!='(')
                        {
                            popped=pop(outputstack,topoutputstack);
                            topoutputstack--;
                            toptempstack=push(tempstack,toptempstack,popped);
                        }
                        popped=pop(symbolstack,topsymbolstack);
                        topsymbolstack--;
                        topoutputstack--;//to over write the bracket position
                        topoutputstack=push(outputstack,topoutputstack,popped);
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

                            char popped,tempstack[20];
                            int toptempstack=-1;
                             while((int)outputstack[topoutputstack]!=(int)copyarrstring[i]-2)
                            {
                            popped=pop(outputstack,topoutputstack);
                            topoutputstack--;
                            toptempstack=push(tempstack,toptempstack,popped);
                            }
                            popped=pop(symbolstack,topsymbolstack);
                            topsymbolstack--;
                            topoutputstack--;//to over write the bracket position
                            topoutputstack=push(outputstack,topoutputstack,popped);
                            for(int j=toptempstack;j>=0;j--)
                            {
                                popped=pop(tempstack,j);
                                toptempstack--;
                                topoutputstack=push(outputstack,topoutputstack,popped);
                            }
                            outputstack[topoutputstack+1]='\0';
                      }


                    }
                    i++;
        }
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
