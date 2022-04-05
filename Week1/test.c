#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<ctype.h>
#include<stdbool.h>
#include"bst.h"

bool isStopw(char stopArr[][10], int n, char word[]){
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(stopArr[i], word) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
   FILE *text, *stopw;
   int numOfStopw = 0;
   int indexOfLine = 1; //so dong tinh tu 1
   char stopArr[20][10];
   char w[20];
   char check[3];
   char c[2];
   c[1]='\0';
   bool isEnd = true;
   elementType tmp;
   treeType tree;

   makeNullTree(&tree);
   stopw = fopen("stopw.txt","r");

   if(stopw == NULL) {
      perror("ERROR");
      return(-1);
   }

   while (!feof(stopw)) {
       fscanf(stopw,"%s\n",stopArr[numOfStopw]);
       numOfStopw++;
   }
   
   text = fopen("van_ban.txt","r");
   if(text == NULL) {
      perror("Can not oppen file !!!");
      return(-1);
   }

   while (!feof(text)) {
        c[0] = fgetc(text);
        //kiem tra co phai ten rieng khong
        //neu ky tu sau dau '.' thi tolower
        if (isupper(c[0]) != 0) {
            fseek( text, -3, SEEK_CUR );
            for (int i = 0; i < 3; i++)
            {
                c[0] = fgetc(text);
                check[i] = c[0];
            }

            if (check[0] == '.') {
                c[0] = tolower(c[0]);
            }
        }
        //neu la ky tu alpha thi concat w
       if (isalpha(c[0])) {
            strcat(w,c);
        } else {     
            //neu w la tu ngu, w khong phai stopw, chu cai dau khong viet hoa thi them vao tree
            if (isalpha(w[0]) && isupper(w[0])==0 && !isStopw(stopArr, numOfStopw, w)) {
                strcpy(tmp.word, w);
                tmp.frequency = 1;
                tmp.lineArr = (int *)malloc(sizeof(int));
                tmp.lineArr[0] = indexOfLine;
                tmp.numOfLine = 1;
                insertNode(tmp, &tree);
            }
            strcpy(w, "");
            //neu la ky tu xuong dong
            if (c[0] == '\n') {
                indexOfLine++;
            }
       }
   }

   
   inOrderPrint(tree);
   freeTree(tree);
   fclose(text);
   fclose(stopw);
   return 0;
}


