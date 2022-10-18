const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const fs = require('fs')
var data;
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended:false}));
app.use(
    bodyParser.raw({ type: 'application/x-www-form-urlencoded' }),
    function (req, res, next) {
      try {
        req.body = JSON.parse(req.body)
      } catch (err) {
        log.info('application/x-www-form-urlencoded JSON PARSE ERROR : ', err);
        req.body = require('qs').parse(req.body.toString());
      }
      next();
    }
  );
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
    extended: true
  }));
app.get('/ui', (req, res, callback) => {
    const promise = new Promise(function(resolve, reject) {
        var data = fs.readFileSync('test.txt', 'utf-8');
        res.send( { value: data } )
    });
    return promise;
});

app.post('/ui', (req, res, callback) => {
    const promise = new Promise(function(resolve, reject) {
        var data = req.body.value + ''
        console.log(data)
        fs.writeFileSync('test.txt', data , 'utf-8');
        res.send(`OK ${data}`);
    });
    return promise;
});

app.listen(8080, (req,res) => {
    console.log("SERVER ON!")
});