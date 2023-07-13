class Solution {

 int dx[4] = {1,-1,0,0};
 int dy[4] = {0, 0,-1,1};

void solve(vector<vector<int>>& image,int r,int c, int sr, int sc, int color,int init){
    if(sr < 0 || sc < 0 || sr >= r || sc >= c){
        return;
    }

    if(image[sr][sc] == color || image[sr][sc] != init){
        return;
    }
    
    image[sr][sc] = color;

    for(int i = 0; i < 4; i++){
        solve(image,r,c,sr+dx[i],sc+dy[i],color,init);
    }

}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        int init = image[sr][sc];
        solve(image,r,c,sr,sc,color,init);
        return image;
    }
};