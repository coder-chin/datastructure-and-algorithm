#include <iostream>
using namespace std;
int a[100000];
int tree[200007];
void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = a[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

void add(int node, int start, int end, int id, int val) {
  if (start == end) {
    a[id] += val;
    tree[node] += val;
  } else {
    int mid = (start + end) / 2;
    if (start <= id and id <= mid) {
      add(2 * node, start, mid, id, val);
    } else {
      add(2 * node + 1, mid + 1, end, id, val);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

void sub(int node, int start, int end, int id, int val) {
  if (start == end) {
    a[id] -= val;
    tree[node] -= val;
  } else {
    int mid = (start + end) / 2;
    if (start <= id and id <= mid) {
      sub(2 * node, start, mid, id, val);
    } else {
      sub(2 * node + 1, mid + 1, end, id, val);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

int query(int node, int start, int end, int l, int r) {
  if (r < start or end < l)
    return 0;
  if (l <= start and end <= r)
    return tree[node];
  int mid = (start + end) / 2;
  int p1 = query(2 * node, start, mid, l, r);
  int p2 = query(2 * node + 1, mid + 1, end, l, r);
  return (p1 + p2);
}

int main() {
  int t;
  cin >> t;
  int num = 0;
  while (t--) {
    num++;
    cout << "Case " << num << ":\n";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    string s;
    int b, c;
    build(1, 1, n);

    while (cin >> s) {
      if (s == "End")
        break;
      if (s == "Add") {
        cin >> b >> c;
        add(1, 1, n, c, b);
      }
      if (s == "Sub") {
        cin >> b >> c;
        sub(1, 1, n, c, b);
      }
      if (s == "Query") {
        cin >> b >> c;
        // cout << b << c << endl;
        cout << query(1, 1, n, b, c) << endl;
      }
    }
  }
}
