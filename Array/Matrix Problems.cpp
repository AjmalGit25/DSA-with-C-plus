/* 1. Common Setup (VERY IMPORTANT) */

// Almost every grid problem starts like this:
int rows = grid.size();
int cols = grid[0].size();


// Movement directions (4-directional)
vector<pair<int,int>> dirs = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};


/* 4-direction */
{1,0}, {-1,0}, {0,1}, {0,-1}

/* Used in most problems like:       											  (r-1, c)
		Number of Islands															 |
		Flood Fill														(r, c-1) <- (r, c) -> (r, c+1)
		Shortest Path (grid)														 |															         
																	              (r+1, c)

*/


/* 8-direction (includes diagonals)  */
{1,0}, {-1,0}, {0,1}, {0,-1},
{1,1}, {1,-1}, {-1,1}, {-1,-1}

/*																			(r-1,c-1)  (r-1,c)  (r-1,c+1)
																			(r,  c-1)  (r,  c)  (r,  c+1)
																			(r+1,c-1)  (r+1,c)  (r+1,c+1)

------------------------------------------------------------------

 Move     			| New Position 
--------------------| ------------ 
 {1,0}					(r+1, c)				// move DOWN
 {-1,0}					(r-1, c)				// move UP
 {0,1}					(r, c+1)				// move RIGHT
 {0,-1}					(r, c-1)				// move LEFT

*/

// Instead of writing 4 calls manually, use a loop:
vector<pair<int,int>> dirs = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};

for (auto [dx, dy] : dirs) {
    dfs(r + dx, c + dy, grid);
}


// ------------------------------------------------------

/* 2. DFS Example (Number of Islands) */

// Problem idea: Count connected components of '1'
void dfs (int r, int c, vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Out of bounds or water
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
        return;

    // mark visited
    grid[r][c] = '0';

    // explore neighbors
    dfs (r+1, c, grid); // down
	dfs (r-1, c, grid); // up
	dfs (r, c+1, grid); // right
	dfs (r, c-1, grid); // left
}

// Driver
int numIslands (vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                dfs (i, j, grid);
                count++;
            }
        }
    }
    return count;
}


/* 3. BFS Example (Shortest Path / Flood Fill) */

// BFS is used when you need minimum steps
void bfs (int r, int c, vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int,int>> q;
    q.push ({r, c});

    vector<pair<int,int>> dirs = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;

            // boundary check
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols 
                && grid[nx][ny] == 1) {

                grid[nx][ny] = 0; // mark visited
                q.push ({nx, ny});
            }
        }
    }
}


/* 4. Key Pattern (MUST Remember) */

// Boundary Check (MOST IMPORTANT)
if (r < 0 || c < 0 || r >= rows || c >= cols)


// Traversal Template
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        // start DFS/BFS from here
    }
}


// ======================================================= //

/*

Vecotr in Matrix Problems


*/