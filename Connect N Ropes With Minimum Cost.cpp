
/*https://www.codingninjas.com/codestudio/problems/connect-n-ropes-with-minimum-cost_630476?leftPanelTab=0*/


long long connectRopes(int* arr, int n)
{
    priority_queue<long long ,vector<long long>,greater<long long>>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    long long cost=0;
    while(pq.size()>1){
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();
        long long c=a+b;
        cost=cost+c;
        pq.push(c);
    }
    return cost;
}
