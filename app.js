
var express = require('express');
var path = require('path');
var app = express();
var http = require('http').Server(app);
var alarms = { }
var now = new Date();
var strDateTime = [[AddZero(now.getDate()), AddZero(now.getMonth() + 1), now.getFullYear()].join("/"),now.getDay(), [AddZero(now.getHours()), AddZero(now.getMinutes())].join(":"), now.getHours() >= 12 ? "PM" : "AM"].join(" ");
var bodyParser = require('body-parser');
var day = now.getDay();


function AddZero(num) {
    return (num >= 0 && num < 10) ? "0" + num : num + "";
}

function tick () {
var now = new Date();
console.log(now);

 if (alarm.hour ==  now.getHours() &&
 	//alarm.day ==  now.getDay() &&
 	alarm.year ==  now.getFullYear() &&
 	alarm.minutes == now.getMinutes()){
    (console.log('yes'));
		} else {
	console.log('nope');
	}
}


var alarm = {
   day: 0,
   month: 0,
   date:0,
   year:0,
	hour: 0,
	minutes: 0,	
}

// app.set('views', path.join(__dirname, 'views'));
// app.set('view engine', 'jade');

app.use(express.static(path.join(__dirname, 'public')));
app.use(bodyParser.urlencoded());
app.use(bodyParser.json());
// app.get("alarm/", function(req, res){
// res.render('index', {title : "alarmclocks"});


// });
app.get('/', function(req, res){
	res.sendfile('form.html');
});

app.get('/alarm', function (req, res) {
	// console.log('help!')
	res.send(alarm.hour + alarm.minutes);
	//console.log(alarm.hour);
	//res.send(alarm_type)

	//time, output, state, active,repeat
});
app.get("/setAlarm", function(req, res){
	console.log(req.body)
	alarm = req.body;
	// console.log(alarm.date);
	var newDate = new Date(alarm.date);
	
	alarm.year = newDate.getFullYear();
	alarm.date = newDate.getDate();
	alarm.month= newDate.getMonth();
	alarm.hour = newDate.getHours();
	alarm.minutes  = newDate.getMinutes();
	console.log(alarm)
	// console.log(now.getHours());
	// console.log(now.getMonth());
	// alarm.alarmType = req.params.alarm_type;
	res.send(req.params.alarm)
});

// app.get("/alarm/", function(req, res){
// 	console.log(req.params.alarm_type);
// 	alarm.alarmType = req.params.alarm_type;
// 	res.send(req.params.alarm_type);
// });

app.get("/alarm/light/time/", function(req, res){
	res.send(alarm);
});
app.get("/alarm/sound/time/", function(req, res){
	res.send(alarm);
});
app.get("/alarm/:alarm_type/time/:hour", function(req, res){
	res.send(alarm.hour);
});

app.get("/alarm/alarm_type/time/minute", function(req, res){
	res.send(alarm.hour);
});
	
app.get("/alarm/:val/state/:val", function(req, res){
res.send(alarm);
});

app.get("/alarm/:val/active/:val", function(req, res){
res.send(alarm);
});
app.get("/alarm/:val/repeat/:val", function(req, res){
res.send(alarm);
});

setInterval(tick, 1000);
http.listen(8080, function(){
	console.log("listening on port 8080!!!");
});