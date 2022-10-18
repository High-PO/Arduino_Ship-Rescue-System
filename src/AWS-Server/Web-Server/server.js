const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const request = require('request');
const { rejects } = require('assert');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended:false}));
function sleep(ms) {
    const wakeUpTime = Date.now() + ms;
    while (Date.now() < wakeUpTime) {}
}


app.listen(8080, (req,res) => {
    console.log("SERVER ON!")
});
let url = "http://ip/ui";
function doRequest(url) {
    return new Promise(function (resolve, reject) {
      request(url, function (error, response) {
        if (!error && response.statusCode == 200) {
          resolve(response);
        } else {
          reject(error);
        }
      });
    });
}

app.get('/', (req, res, callback) => {
    const promise = new Promise(function(resolve, reject) {
        doRequest(url).then(function (ress) {
            data = ress.body
            let stringifyData = data;
            let object = JSON.parse(stringifyData);
            let object2 = JSON.parse(stringifyData, (key, val) => (key == "age" ? val * 2 : val));
            console.log(object2);
            if (object2.value == "Safe"){
                res.sendfile(__dirname + '/safe.html');
            }
            else if (object2.value == "Warring"){
                res.sendfile(__dirname + '/warring.html');
            }
            else{
                res.send("Data Setup Error :(")
            }
        });
    });
    return promise;
});