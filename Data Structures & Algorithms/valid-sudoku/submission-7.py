class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        for row in range(9):
            seen =set()
            for col in range(9):
                if board[row][col] == ".":
                    continue
                if board[row][col] in seen:
                    return False
                seen.add(board[row][col])
        
        
        for row in range(9):
            seen =set()
            for col in range(9):
                if board[col][row] == ".":
                    continue
                if board[col][row] in seen:
                    return False
                seen.add(board[col][row])
        

        for sq in range(9):
            seen=set()
            for i in range(3):
                for j in range(3):
                    r = (sq//3)*3+i
                    c = (sq%3)*3+j
                    if board[r][c] == ".":
                        continue
                    if board[r][c] in seen:
                        return False
                    seen.add(board[r][c])
        
        return True