#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using ll = long long;

ll arr[100005], tree[400005], lazy[400005];

ll init(ll node, ll s, ll e) {
    if (s == e) return tree[node] = arr[s];
    ll mid = (s + e) >> 1;
    return tree[node] = init(2 * node, s, mid) + init(2 * node + 1, mid + 1, e);
}

void propagate(ll node, ll s, ll e) {
    if (lazy[node]) {
        tree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void update(ll node, ll s, ll e, ll qs, ll qe, ll add) {
    propagate(node, s, e);
    if (qe < s || e < qs) return;
    if (qs <= s && e <= qe) {
        tree[node] += (e - s + 1) * add;
        if (s != e) {
            lazy[2 * node] += add;
            lazy[2 * node + 1] += add;
        }
        return;
    }
    ll mid = (s + e) >> 1;
    update(2 * node, s, mid, qs, qe, add);
    update(2 * node + 1, mid + 1, e, qs, qe, add);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(ll node, ll s, ll e, ll qs, ll qe) {
    propagate(node, s, e);
    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return tree[node];
    ll mid = (s + e) >> 1;
    return query(2 * node, s, mid, qs, qe) + query(2 * node + 1, mid + 1, e, qs, qe);
}

int main() {
    ll n; scanf("%lld", &n);
    for (ll i = 0; i < n; i++) scanf("%lld", arr + i);
    init(1, 0, n - 1);

    ll q; scanf("%lld", &q);
    while (q--) {
        ll k; scanf("%lld", &k);
        if (k == 1) {
            ll a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
            update(1, 0, n - 1, a - 1, b - 1, c);
        }
        else {
            ll a; scanf("%lld", &a);
            printf("%lld\n", query(1, 0, n - 1, a - 1, a - 1));
        }
    }
}