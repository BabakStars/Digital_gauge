const char index_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
   
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script>
    var timer = setInterval(function(){
        var req = new XMLHttpRequest();
        req.open("GET","http://192.168.1.150/SET?password=1234", true)
        req.onreadystatechange = function(){
         
            if(this.readyState == 4 && this.status ==200)
                    {
                        var poi = this.responseText;
                        poi = ((poi/1023)*100);
                        document.getElementById('pointer').style.transform = `rotate(${poi}deg)`;
                        document.getElementById('hh').innerHTML = poi;
                    }
                };
                req.send();
                req.close();
                return;
    },1000);
</script>
</head>
<style>
    #ex1{
        border: 1px solid rgb(0, 0, 0);
        padding: 10px;
        border-radius: 50%;
        height: 480px;
        width: 480px;
        background-image: url("https://s2.uupload.ir/files/untitled_mgl.jpg");
        background-repeat: no-repeat;
        margin: auto;
    }
    #pointer
    {
    -moz-transition: all 0.4s linear;
    -webkit-transition: all 0.4s linear;
    -o-transition: all 0.4s linear;
    -ms-transition: all 0.4s linear;
    transition: all 0.4s linear;
    }
</style>

<body>
    <div id="ex1">
        <img src="https://s2.uupload.ir/files/g1_3cl.png" id="pointer" style="width: 500px; rotate:180deg; margin-left: -5px; margin-top: 190px; " alt="185">
    </div>
<h1 id="hh" style="text-align: center;">.</h1>
</body>
</html>
)=====";
