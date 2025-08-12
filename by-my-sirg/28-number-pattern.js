(function (){
    let k = 1
    for (let i = 1; i <=5 ; i++ ){
        let line  = ''; 
        let temp = [];
        for (let j= 1; j <= i; j++ ){
            j < i ? temp.push(`${k}*`) : temp.push(k)
            k++
        }
        if ( i % 2 === 0 ) temp.reverse();
        line = temp.join('')
        console.log(line);
    }
})()