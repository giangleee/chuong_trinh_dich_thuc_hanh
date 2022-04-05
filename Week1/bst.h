//THU VIEN DANH CHO CAY NHI PHAN TIM KIEM (BST)

typedef struct bst
{
    char word[20];
    int frequency;
    int numOfLine;
    int *lineArr;
} elementType;


typedef struct node_type{
  elementType element;
  struct node_type *left, *right;
} nodeType;

typedef nodeType *treeType;//treetype la 1 con tro tro den kieu Node. treeType = Node*

//Ham so sanh 2 phan tu dang elementType bat ky
int compare(elementType a, elementType b){
    return strcmp(a.word, b.word);
}

//Khoi tao cay rong
void makeNullTree(treeType *T){
  (*T) = NULL;
}

//Tao cay tim kiem nhi phan
void insertNode(elementType x, treeType *root){    //Neu truyen vao con tro -> thay doi ca tree. Neu chi truyen vao root bthg -> phai return de lay gia tri
  if(*root == NULL){//Truong hop co so: nut rong
    /*Create a new node for key x*/
    *root = (nodeType*)malloc(sizeof(nodeType));
    (*root)-> element= x;
    (*root)->left = NULL; 
    (*root)->right = NULL;
  }
  else if(compare(x, (*root)->element) < 0)//Neu khoa them vao < khoa nut goc 
    insertNode(x, &(*root)->left);
  
  else if(compare(x, (*root)->element) > 0)
    insertNode(x, &(*root)->right);
  else {
    (*root)->element.frequency++;
    if ((*root)->element.lineArr[(*root)->element.numOfLine - 1] != x.lineArr[0])
    {
      (*root)->element.numOfLine++;
      (*root)->element.lineArr = realloc((*root)->element.lineArr, (*root)->element.numOfLine * sizeof(int));
      (*root)->element.lineArr[(*root)->element.numOfLine - 1] = x.lineArr[0];
    }
  }
}

//Ham duyet cay theo thu tu giua
void inOrderPrint(treeType root){
  if(root != NULL){
    inOrderPrint(root->left);
    printf("%s", root->element.word);
    for (int i = 0; i < root->element.numOfLine; i++)
    {
      printf(", %d", root->element.lineArr[i]);
    }
    printf("\n");
    inOrderPrint(root->right);
  }
}

//Ham giai phong toan bo cay
void freeTree(treeType root){
  if(root != NULL){
    freeTree(root->left);
    freeTree(root->right);
    free((void*)root);
  }
}