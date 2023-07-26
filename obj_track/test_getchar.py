from mylib.getchar import Getchar

def main(args=None):
    kb = Getchar()
    key = ''
    
    while key!='Q':
    
        key = kb.getch()
        if key == 'w':
            print("up")
        elif key == 's':
            print("down")
        elif key == 'a':
            print("left")
        elif key == 'd':
            print("rigjt")        
        

if __name__ == '__main__':
    main()

