**NC93** **设计LRU缓存结构**

```c++
class Solution {
public:
    vector<int> LRU(vector<vector<int> > &operators, int k) {
        map<int, int> cacheMap;  //存放键值对
        int num = 0;
        vector<int> ret;
        
        for(auto item: operators) {
            if(item[0] == 1) { //需要写入 
                auto it = cacheMap.find(item[1]);
                if(it != cacheMap.end()) { //如果已经存在
                    cacheMap.erase(it);    //删除并放到最后
                    cacheMap.insert(pair<int, int>(item[1], item[2]));
                } else {                                       //不存在就向后添加
                    cacheMap.insert(pair<int, int>(item[1], item[2]));
                    num++;
                }
                if(num > k) {                                   //满了的话删除前面的
                    cacheMap.erase(cacheMap.begin());
                    num--;
                }
            }
            else if(item[0] == 2) {    //读操作
                if(cacheMap.find(item[1]) != cacheMap.end()) {
                    auto it = cacheMap.find(item[1]);
                    int key = it->first, value = it->second;
                    cacheMap.erase(it);
                    cacheMap.insert(pair<int, int>(key, value));
                    ret.push_back(value);
                } else {
                    ret.push_back(-1);
                }
            }
        }
        return ret;
    }
};
```

