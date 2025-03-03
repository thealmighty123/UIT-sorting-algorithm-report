#include <bits/stdc++.h>
#include <fstream>
#define TASK "test"
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i = a; i <= b ; i++)
#define FOD(i,a,b) for(int i = a; i >= b ; i--)
#define task "test"
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i) // đếm số bit đang bật
#define BIT(x, i) ((x) & MASK(i)) // trạng thái của bit thứ i trong x
#define SET_ON(x, i) ((x) | MASK(i)) // bật bit thứ i trong x
#define SET_OFF(x, i) ((x) & ~MASK(i)) //  tắt bit thứ i trong x
#define ll long long
#define vt vector
#define C make_pair
template<typename T> bool maximize(T &res, const T &val) { if (res < val) { res = val; return true; } return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val) { res = val; return true; } return false; }
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
const int mod = 1e9 + 7;
const int LOG = 18;
const int N = 1e6 + 9;
const int MAXN = 16;
const ll INF = 1e18 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double arr[N];
int n;

double a[N];

void mergeSort(double data[N], int left, int right) {
    if (left == right) {
        // Dãy chỉ gồm 1 phần tử, ta không cần sắp xếp.
        return ;
    }
    int mid = (left + right) / 2;
    // Sắp xếp 2 phần
    mergeSort(data, left, mid);
    mergeSort(data, mid+1, right);

    // Trộn 2 phần đã sắp xếp lại
    int i = left, j = mid + 1; // phần tử đang xét của mỗi nửa
    int cur = 0; // chỉ số trên mảng a

    while (i <= mid || j <= right) { // chừng nào còn 1 phần chưa hết phần tử.
        if (i > mid) {
            // bên trái không còn phần tử nào
            a[cur++] = data[j++];
        } else if (j > right) {
            // bên phải không còn phần tử nào
            a[cur++] = data[i++];
        } else if (data[i] < data[j]) {
            // phần tử bên trái nhỏ hơn
            a[cur++] = data[i++];
        } else {
            a[cur++] = data[j++];
        }
    }
    for (int i = 0; i < cur; i++)
        data[left + i] = a[i];
}

double process_file(const string& input_file, vector<double>& all_numbers) {
    ifstream file(input_file);
    if (!file) {
        cerr << "Error: Cannot open file " << input_file << "\n";
        return 0.0;
    }
    
    auto start = chrono::high_resolution_clock::now();
    file >> n;
    FOR(i,1,n) {
        file >> arr[i];
        all_numbers.push_back(arr[i]);
    }
    file.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;

    mergeSort(arr, 1, n);
    
    return duration.count();
}

int main() {
    string input_folder = "test";
    vector<double> all_numbers;
    
    for (const auto& entry : filesystem::directory_iterator(input_folder)) {
        if (entry.path().extension() == ".inp") {
            string input_path = entry.path().string();
            double time_taken = process_file(input_path, all_numbers);
            cout << "Processed " << input_path << " in " << fixed << setprecision(4) << time_taken << " ms." << endl;
        }
    }
    
    return 0;
}
