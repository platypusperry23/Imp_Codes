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
int main()
{
    char letters[100000];
    printf("Please Enter the letters in the bag of letters \n");
    scanf("%s",letters);
    printf("Please Enter the word to be checked\n");
    char word[100000];
    scanf("%s",word);
    int a= matching(letters,word);
     for (int i = 0; i < strlen(word); i++)
    {
        word[i]=toupper(word[i]);
    }
     if(a!=0)
     {
         printf("\n The word is made from the letters in the bag \n");
            FILE *filePointer ;
        filePointer = fopen("dic.txt","r");
        char dic_words[50];
        int flags=0;
        while (1)
        {
            fgets(dic_words,50,filePointer);
                if((int)dic_words[0]>(int)word[0])
                    {
                        flags=1;
                        break;
                    }
            flags=0;
                int length;
                if(strlen(dic_words)>strlen(word))
                length=strlen(dic_words)-1;
                else
                length=strlen(word);
            for(int i=0;i<length;i++)
            {               
               if(word[i]!=dic_words[i])
                {
                    flags=1;
                    break;
                }
            }
            if(flags==0)
            {
                //printf("%s\n",dic_words);
            break;
            }
        }
        fclose(filePointer);
            if(flags==0)
            {
                    printf("\n The word is Present in the Dictonary\n");
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
                int len=strlen(letters);
                int len_w=strlen(word);
                int good=   (len-1)*len_w;
                int bad;
                if(1<(3*(len+1-len_w)))
                bad=(3*(len+1-len_w));
                else
                bad=1;
                score = score*(good-bad);
                printf("Score of the word %s = %d \n\n",word,score);
            }
            else
            {
                printf("\nSorry The word is not present in the dictonary so is invalid\n");
            }
     }
     else
     {
         printf("\nSorry The word is not made from letters in the bag so is Invalid\n");
     }
}   