class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char,bool> row;
    unordered_map<char,bool> column;
    unordered_map<char,bool> cell;
    
    for(int i = 0 ;i < 9 ;i++)
    {
        for(int j = 0; j< 9;j++)
        {
            if(board[i][j] != '.')//i行j列
            {
                if(row[board[i][j]] == true)    //true表示已经添加索引了 表示重复
                    return false;
                else
                    row[board[i][j]] = true;    //hash map 引用用[]
            }
            
            
            if(board[j][i] != '.')
            {
                if(column[board[j][i]] == true)
                    return false;
                else
                    column[board[j][i]] = true;
            }
            
            
            //cell是按照一个cell那样排的, 要找到每个九宫格对应的board数组中的值 (0,5) -> (1,2)
            //i j 这里开始表示第i个九宫格第j个元素
            //先确定从board的哪一行取:
            //对于i: 第0,1,2个cell都是从第0行取 3,4,5个cell都是从第三行区, 6,7,8都是第6行取
            //但是还要加上j的偏移: 0,1,2偏移都是0, 3,4,5偏移1行, 678偏移2行
            //再确定从board的哪一列取: 同理
            //
            if(board[(i/3)*3+(j/3)][(i%3)*3+(j%3)] != '.')
            {
                if(cell[board[(i/3)*3+(j/3)][(i%3)*3+(j%3)]] == true)
                    return false;
                else
                    cell[board[(i/3)*3+(j/3)][(i%3)*3+(j%3)]] = true;
            }
            
            
            
        }
        row.clear();
        column.clear();
        cell.clear();
    }
    return true;
}
};