//     *
//    **
//   ***
//  ****
// *****   


function print(){
    for (let i = 0; i <= 5 ; i++ ){
        let star = ''
        for (let j = 0; j <= 5; j++){
            if (j >= 5 - i) {
                star += '*'
            } else {
                star += ' '
            }
        }
        console.log(star);
        
    }
}

print()