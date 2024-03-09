#include <stdio.h>
#include <stdlib.h>
#include <cmath>
typedef struct{
    int x;
    int y;
}Point;

void function1(){
    int m, n;
    scanf("%d %d", &m, &n);
    Point a[3];

    for(int i = 0; i < 3; i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }

    long long ans = 0;

    ans += abs(a[0].x - a[1].x) < (m - abs(a[0].x - a[1].x)) ? abs(a[0].x - a[1].x) : (m - abs(a[0].x - a[1].x));
    ans += abs(a[0].y - a[1].y) < (n - abs(a[0].y - a[1].y)) ? abs(a[0].y - a[1].y) : (n - abs(a[0].y - a[1].y));
    ans += abs(a[1].x - a[2].x) < (m - abs(a[1].x - a[2].x)) ? abs(a[1].x - a[2].x) : (m - abs(a[1].x - a[2].x));
    ans += abs(a[1].y - a[2].y) < (n - abs(a[1].y - a[2].y)) ? abs(a[1].y - a[2].y) : (n - abs(a[1].y - a[2].y));

    printf("%lld\n", ans);
}

int get_size(int* arr, int length){
    int i = 0;
    for(i = 0; i < length; i++)
        if(arr[i] == -1)
            break;
    return i;
}

int ** arr;
long long ans = 0;

void dfs(int *dis, int k, int son, int father, int length){
    if(dis[son] <= k){
        ans++;
    }
    if(son != 0 && dis[son] < k && get_size(arr[son], length) == 1){
        ans+=k - dis[son];
    }
    for(int i = 0; i < get_size(arr[son], length); i++){
        if(arr[son][i] == father) continue;
        dis[arr[son][i]] = dis[son] + 1;
        dfs(dis, k, arr[son][i], son, length);
    }
}
void function2(){
    
    int n, k;
    int u, v;
    scanf("%d %d", &n, &k);

    arr = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = -1;
        }
    }

    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &u, &v);
        arr[u-1][get_size(arr[u-1], n)] = v - 1;
        arr[v-1][get_size(arr[v-1], n)] = u - 1;
    }

    int *dis = (int*)malloc(sizeof(int) * n);
    dis[0] = 0;

    dfs(dis, k, 0, -1, n);
    printf("%lld\n", ans);
}

void function3(){
    double p;
    scanf("%lf", &p);

    double dp[91];
    dp[0] = 0;
    double ans = 0;

    for(int i = 1; i < 90; i++){
        dp[i] = (1 - dp[i-1]) * p;
        ans += i * dp[i];
        dp[i] += dp[i-1];
    }
    dp[90] += (1 - dp[89]);

    for(int i = 0; i <= 90; i++){
        printf("%.7lf\n", dp[i]);
    }

    ans += 90 * dp[90];
    
    printf("%.7lf\n", 1.5 * ans);
}

int main(){

    function3();
    
    return 0;
}