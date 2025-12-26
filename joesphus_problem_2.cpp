#include<bits/stdc++.h>
using namespace std;
class segtree{
    int n = 0;
    vector<int> tree;

    public:
    segtree(int x)
    {
        n = x;
        tree.resize(4*n);
        // just to be on the safe side
    }

    void build(int l, int r, int node)
    {
        // node is just an id into the segtree array
        if(l == r)
        {
            tree[node] = 1;
            return;
        }

        int left = 2*node, right = 2*node + 1;
        int mid = l + (r-l)/2;
        
        build(l, mid, left);
        build(mid+1, r, right);
        // you need to compute parent sums here too
        tree[node] = tree[left] + tree[right];
    }

    void remove(int l, int r, int node, int idx) 
    {
        if(l == r)
        {
            tree[node] = 0;  // mark dead
            return;
        }
        
        int left = 2*node, right = 2*node + 1;
        int mid = l + (r-l)/2;

        // idx is the index which has to be removed. remove by index
        if(mid >= idx)
            remove(l, mid, left, idx);
        else
            remove(mid+1, r, right, idx);

        //sum needs to be recomputed
        tree[node] = tree[left] + tree[right];
    }

    int kth(int l, int r, int node, int k)
    {
        if(l == r)
            return l;
        
        int left = 2*node, right = 2*node + 1;
        int mid = l + (r-l)/2;
        
        if(tree[left] >= k)
            return kth(l, mid, left, k);
        
        return kth(mid+1, r, right, k - tree[left]);        
        
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    segtree st(n);
    st.build(1, n, 1);
    int curr = 0, alive = n;
    while(alive > 0)
    {
        curr = (curr + k)%alive;
        int idx = st.kth(1, n, 1, curr + 1);
        cout << idx << " ";
        // as kth expects 1 indexed
        st.remove(1, n, 1, idx);
        alive--;
    }
    return 0;
}