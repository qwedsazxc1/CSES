#include <iostream>

int max(int a, int b);
int lower_bound(int *base, int left, int right, int target);

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int dp[n + 1] = {}, len = 1;
    int list[n] = {arr[0]};
    for (int i = 1; i < n; i++){
        if (arr[i] > list[len - 1]){
            list[len++] = arr[i];
            continue;
        }
        int index = lower_bound(list, 0, len - 1, arr[i]);
        if (index != -1)
            list[index] = arr[i];
    }
    printf("%d\n", len);
    return 0;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int lower_bound(int *base, int left, int right, int target){
    int ans = -1;
    while (left <= right){
        int mid = (right - left) / 2 + left;
        if (base[mid] >= target){
            ans = mid;
            right = mid - 1;   
            
            continue;
        }
        left = mid + 1;
    }
    return ans;
}