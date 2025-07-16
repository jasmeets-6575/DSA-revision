// (function () {
//     for (let i= 1; i <= 7; i++){
//         let star = '';
//         for (let j = 1; j<= 4; j++){
//             if (j <= i && i <= 4) {
//                 star += '*'
//             }
//             else if (i > 4 && j < 9 - i  ) {
//                 star += '*'
//             }
//         }
//         console.log(star);
//     }
// })()

(function () {
    let star = '';
    let k = 0;
    for (let i= 1; i <= 7; i++){
        i <= 4 ? k++ : k--;
        for (let j = 1; j<= 4; j++){
            if (j <= k) {
                star += '*'
            }
        }
        console.log(star);
    }
})()