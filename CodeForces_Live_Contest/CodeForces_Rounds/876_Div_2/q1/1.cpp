class Solution {
public:
    long long matrixSumQueries(long long n, vector<vector<long long>>& queries) {
        vector<vector<long long>> mat(n + 10 , vector<long long > (n + 10 , 0)) ;
        long long len = queries.size() ;
        for(long long i = 0 ; i < len ; ++i){
            if(queries[i][0] == 0){
                for(long long j = 0 ; j < n ; ++j){
                    mat[queries[i][1]][j] = queries[i][2] ;
                }
            }
            if(queries[i][0] == 1){
                for(long long j = 0 ; j < n ; ++j){
                    mat[j][queries[i][1]] = queries[i][2] ;
                }
            }
        }
        long long sum = 0 ;
        for(long long i = 0 ; i < n ; ++i){
            for(long long j = 0 ; j < n ; ++j){
                sum += mat[i][j] ;
            }
        }
        return sum ;
    }
};