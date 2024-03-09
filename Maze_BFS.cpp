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
    1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

//right, down, left, up
int direction_x[4] = {0, 1, 0, -1};
int direction_y[4] = {1, 0, -1, 0};

typedef struct{
    int x, y;
    int parent;
    int step;
}Node;

typedef struct{
    Node data[MAX_SIZE];
    int front;
    int rear;
}Queue;

int queue_empty(Queue* qu){
    return !((qu->rear - qu->front + MAX_SIZE) % MAX_SIZE);
}

void queue_push(Queue* qu, Node n){
    if(qu->rear == MAX_SIZE){
        printf("Queue is full!\n");
        return;
    }
    qu->data[qu->rear] = n;
    qu->rear = qu->rear + 1;
}

void queue_pop(Queue* qu){
    qu->front = qu->front + 1;
}

typedef struct{
    Node data[MAX_SIZE];
    int front;
    int rear;
}Stack;

void stack_push(Stack* stk, Node n){
    if(stk->rear == MAX_SIZE){
        printf("Queue is full!\n");
        return;
    }
    stk->data[stk->rear] = n;
    stk->rear = stk->rear + 1;
}

int main(){
    bool result = false;
    int visit[MAP_H+2][MAP_W+2];
    for(int i = 0; i < MAP_H+2; i++){
        for(int j = 0; j < MAP_W+2; j++){
            visit[i][j] = 0;
        }
    }

    int start_x, start_y, final_x, final_y;
    scanf("%d %d %d %d", &start_x, &start_y, &final_x, &final_y);

    Queue* qu;
    qu = (Queue*)malloc(sizeof(Queue));
    qu->data[0].x = start_x + 1;
    qu->data[0].y = start_y + 1;
    qu->data[0].parent = 0;
    qu->data[0].step = 0;
    qu->front = 0;
    qu->rear = 1;
    visit[start_x][start_y] = 1;

    while(!queue_empty(qu)){

        int enable_action = 0;

        for(int i = 0; i <= 3; i++){
            int t_x, t_y;
            t_x = qu->data[qu->front].x + direction_x[i];
            t_y = qu->data[qu->front].y + direction_y[i];
            if(map[t_x][t_y] == 0 && visit[t_x][t_y] == 0){
                enable_action = 1;
                Node tmp;
                tmp.x = t_x;
                tmp.y = t_y;
                tmp.parent = qu->front;
                tmp.step = qu->data[qu->front].step + 1;
                queue_push(qu, tmp);
                visit[t_x][t_y] = 1;
            }
        }

        if(qu->data[qu->front].x == final_x+1 && qu->data[qu->front].y == final_y+1){
            if(enable_action == 0){
                result = true;
                break;
            }
            else if(enable_action == 1){
                result = false;
                break;
            }
        }
        queue_pop(qu);
    }
    
    int step = qu->data[qu->front].step;

    Stack* path = (Stack*)malloc(sizeof(Stack));
    path->rear = 0;
    if(result){
        while(qu->data[qu->front].x != qu->data[qu->data[qu->front].parent].x || qu->data[qu->front].y != qu->data[qu->data[qu->front].parent].y){
            stack_push(path, qu->data[qu->front]);
            qu->front = qu->data[qu->front].parent;
        }
        stack_push(path, qu->data[qu->front]);
    }

    printf(result?"true\n":"false\n");

    if(result){
        printf("%d\n", step);
        for(int i = step; i > 0; i--){
            printf("(%d, %d)->", path->data[i].x-1, path->data[i].y-1);
        }
        printf("(%d, %d)\n", path->data[0].x-1, path->data[0].y-1);

        for(int i = step; i > 0; i--){
            int x = path->data[i-1].x - path->data[i].x;
            int y = path->data[i-1].y - path->data[i].y;
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
    free(qu);
    free(path);
}