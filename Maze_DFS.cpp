#include <stdio.h>
#include <stdlib.h>

#define MAP_H 18
#define MAP_W 18
#define MAX_SIZE 350

int map[MAP_H+2][MAP_W+2] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1,
    1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1,
    1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1,
    1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
    1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

//right, down, left, up
int direction_x[4] = {0, 1, 0, -1};
int direction_y[4] = {1, 0, -1, 0};
int min_step = 999999;

typedef struct{
    int x, y;
    int parent;
    int step;
}Node;

typedef struct{
    Node data[MAX_SIZE];
    int rear;
}Stack;

void stack_push(Stack* stk, Node n){
    if(stk->rear == MAX_SIZE){
        printf("Stack if full\n");
        return;
    }
    stk->data[stk->rear] = n;
    stk->rear++;
}

void stack_pop(Stack* stk){
    if(stk->rear == 0){
        printf("Stack is empty\n");
    }
    stk->rear--;
}

Node* stack_top(Stack* stk){
    return stk->data + (stk->rear-1);
}


int main(){
    bool result = false;
    int visit[MAP_H+2][MAP_W+2];
    int start_x, start_y, final_x, final_y;
    Stack* sk = (Stack*)malloc(sizeof(Stack));
    Stack* path = (Stack*)malloc(sizeof(Stack));


    for(int i = 0; i < MAP_H+2; i++){
        for(int j = 0; j < MAP_W+2; j++){
            visit[i][j] = 0;
        }
    }
    
    scanf("%d %d %d %d", &start_x, &start_y, &final_x, &final_y);
    
    sk->data[0].x = start_x + 1;
    sk->data[0].y = start_y + 1;
    sk->data[0].step = 0;
    sk->data[0].parent = 0;
    sk->rear = 1;

    while(sk->rear != 0){

        int enable_action = 0;

        int t_x, t_y;
        for(int i = 0; i <= 3; i++){
            t_x = stack_top(sk)->x + direction_x[i];
            t_y = stack_top(sk)->y + direction_y[i];
            if(map[t_x][t_y] == 0 && visit[t_x][t_y] == 0){
                enable_action = 1;
                break;
            }
        }

        if(enable_action){
            if(stack_top(sk)->x == final_x+1 && stack_top(sk)->y == final_y+1){
                result = false;
                break;
            }
            else{
                Node tmp;
                tmp.x = t_x;
                tmp.y = t_y;
                tmp.parent = sk->rear - 1;
                tmp.step = sk->data[sk->rear - 1].step + 1;
                stack_push(sk, tmp);
                visit[t_x][t_y] = 1;
            }
        }
        else if(enable_action == 0){
            if(stack_top(sk)->x == final_x+1 && stack_top(sk)->y == final_y+1){
                result = true;
                if(sk->data[sk->rear-1].step < min_step){
                    min_step = sk->data[sk->rear-1].step;
                    for(int i = 0; i < sk->rear; i++){
                        path->data[i] = sk->data[i];
                    }
                    path->rear = sk->rear;
                }
            }
            stack_pop(sk);
        }
    }

    printf(result?"true\n":"false\n");

    if(result){
        printf("%d\n",min_step);
        for(int i = 0; i < path->rear - 1; i++){
            int x = path->data[i+1].x - path->data[i].x;
            int y = path->data[i+1].y - path->data[i].y;
            if(x == 0 && y == 1){
                printf("right ");
            }
            else if(x == 1 && y == 0){
                printf("down ");
            }
            else if(x == 0 && y == -1){
                printf("left ");
            }
            else if(x == -1 && y == 0){
                printf("up ");
            }
        }
        printf("\n");
    }
    
}