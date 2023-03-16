for (let i = 0; i < document.querySelectorAll(".mcq").length; i++) {
    document.querySelectorAll(".mcq")[i].addEventListener("click", function(){

        if (this.innerHTML === "Taylor Launter") {

            document.querySelector('#feedback1').innerHTML = 'Correct!';
            this.style.backgroundColor = '#008000';

        }
        else {


            document.querySelector('#feedback1').innerHTML = 'Incorrect!';
            this.style.backgroundColor = '#ff0000';

        }


    });

}

document.querySelector('.response').addEventListener('click', function(){
    let input = document.querySelector('input');
    if(input.value == 'Red'){
        input.style.backgroundColor = '#008000';
        document.querySelector('#feedback2').innerHTML = 'Correct!';
    } else {
        input.style.backgroundColor = '#ff0000';
        document.querySelector('#feedback2').innerHTML = 'Incorrect';
    }
 });
