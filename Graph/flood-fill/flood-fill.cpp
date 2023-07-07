class Solution {
public:

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void fill(vector<vector<int>>&image,int r,int c,int i,int j,int color,int prev){
    if(i < 0 || j < 0 || i >= r || j >= c) {
        return;
    }



    if(image[i][j] != prev || image[i][j] == color){
        return;
    }

    image[i][j] = color;
   
    for(int k = 0; k < 4; k++){
        fill(image,r,c,i+dx[k],j+dy[k],color,prev);
    } 
}


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        fill(image,r,c,sr,sc,color,image[sr][sc]);
        return image;
    }
};