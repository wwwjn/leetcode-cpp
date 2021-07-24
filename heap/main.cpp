#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template<typename Item>
class maxHeap{
private:
    Item* data;
    int maxSize;
    int count;
    //打印的辅助函数
    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }
    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
public:
    maxHeap(int capacity){
        data = new Item[capacity];  // index starts from zero
        count = 0;  // index: [0.... count)
        maxSize = capacity;
    }
    maxHeap(Item arr[], int n){  // 这样建堆更快O(n)。逐个插入堆的时间复杂度是O(nlogn)
        data = new Item[n];
        maxSize = n;
        for(int i = 0; i < n; i++){
            data[i] = arr[i];
        }
        count = n;
        for(int j = count/2 - 1; j >= 0; j --){
            ShiftDown(j);
        }
    }
    ~maxHeap(){
        delete [] data;
    }
    int size(){
        return count;
    }
    bool isempty(){
        return count == 0;
    }
    bool insert(int t){
        if(count == maxSize) return false;
        // [0.... count-1]
        data[count] = t;
        ShiftUp(count);
        count ++;
    }
    void ShiftUp(int position){
        while(position > 0 && data[position] > data[parent(position)]){
            // 此处还可以优化swap的次数 -> 采用填坑的思路
            swap(data[position], data[parent(position)]);
            position = parent(position);
        }
    }
    Item extratMax(){
        assert(count > 0);
        Item res = data[0];
        data[0] = data[count - 1];
        count --;
        ShiftDown(0);
        return res;
    }
    void ShiftDown(int position){
        while(leftChild(position) < count){  // 存在左孩子
            int tmp_p = leftChild(position);
            if(data[rightChild(position)] > data[leftChild(position)])
                tmp_p ++;  // tmp_p指向更大的子节点
            if(data[tmp_p] < data[position]) break;
            swap(data[tmp_p], data[position]);
            position = tmp_p;
        }
    }
    int parent(int position){
        return (position - 1)/2;
    }
    int leftChild(int position){
        return 2 * position + 1;
    }
    int rightChild(int position){
        return 2 * position + 2;
    }
    // 以树状打印整个堆结构
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 0 ; i < size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert(data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 0;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }
};


int main() {
    maxHeap<int> maxheap = maxHeap<int>(100);

    srand(time(NULL));
    for(int i = 0; i < 15; i ++){
        int tmp = rand()%100;
        maxheap.insert(tmp);
    }
    maxheap.testPrint();
    while(!maxheap.isempty()){
        cout << maxheap.extratMax() << " ";
    }
    cout << endl;

    int arr[] = {98,94, 77, 75, 88, 71, 69, 9, 42, 10, 71, 28, 28, 33, 46};
    maxHeap<int> m = maxHeap<int>(arr, sizeof(arr)/sizeof(int));
    while(!m.isempty()){ cout<< m.extratMax() << " "; }
    cout << endl;
    return 0;
}
