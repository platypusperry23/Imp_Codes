#include <stdio.h>
#include <string.h>

int matching(char let[],char word[])
{
int freq_l[27],freq_w[27];
for(int i=0;i<strlen(let);i++)
{
if(let[i]=='*')
freq_l[26]+=1;
else
freq_l[(int)(let[i])-97]+=1;
}
for(int i=0;i<strlen(word);i++)
{
if(freq_l[word[i]-97]>0)
            freq_l[word[i]-97]-=1;
        else if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
        {
            if(freq_l[26]>0)
            freq_l[26]-=1;
            else
            return 0;
        }
        else
        {
            return 0;
        }
}

    return 1;
}

int score(char word[],int len)
{
    int score=0;
    for(int i=0;i<strlen(word);i++)
    {
        if(word[i]=='q' || word[i]=='z')
            score+=10;
        else if(word[i]=='j'||word[i]=='x')
            score+=8;
        else if(word[i]=='k')
            score+=5;
        else if(word[i]=='f'|| word[i]=='h'||word[i]=='v'|| word[i]=='w'||word[i]=='y')
            score+=4;
        else if(word[i]=='b'|| word[i]=='c'||word[i]=='m'||word[i]=='p')
            score+=3;
        else if(word[i]=='d'|| word[i]=='g')
            score+=2;
        else
            score+=1;
        }

        int len_w=strlen(word);
        int good=(len-1)*len_w;
        int bad;
        if(1<(3*(len+1-len_w)))
        bad=(3*(len+1-len_w));
        else
        bad=1;
        score = score*(good-bad);
       
return score;        
}

int main()
{
char letters[100000];
    printf("Please Enter the letters in the bag of letters \n");
    scanf("%s",letters);
    int len=strlen(letters);
    
    FILE *filePointer ;
        filePointer = fopen("dic.txt","r");
        char dic_words[50];
        int flag=0;
        int max=0,size=50;
        char duplicate[50];
       
        int T=200000;
        while (T--)
        {
            fgets(dic_words,50,filePointer);
               if(dic_words[0]=='0')
                break;
                 for (int i = 0; i < strlen(dic_words); i++)
                    {
                        dic_words[i]=tolower(dic_words[i]);
                    }
                    printf("%s\n",dic_words);
                    int a= matching(letters,dic_words);
               
                     if(a!=0)
                     {
                         flag=1;
                     int  x=score(dic_words,len);
                      
                        if(x>max)
                        {
                             max=x;
                            int i=0;
                            while(dic_words[i] !='\0')
                            {
                            duplicate[i]=dic_words[i];
                            i++;
                            }
                            duplicate[i]='\0';
                             
                        }
                      
                      }       
                    
        }
        fclose(filePointer);
          
            if(flag==1)
            {
            printf("\nEffective word is present in the dictonary\n");
            printf("\nThe word is %s\n",duplicate);
}
   if(flag==0)
                printf("\nSorry No word can be form using bag of letter present in the dictonary so is invalid\n");
           
}