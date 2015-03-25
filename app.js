var express = require('express');
var path = require('path');
var app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var para = {

	"parameters" : [],
	"max_values" : [500, 10, 10] 
}

var maxPotVal = 1023;


// app.set('views', path.join(__dirname, 'views'));
// app.set('view engine', 'jade');

// app.use(express.static(path.join(__dirname, 'public')));

app.get("/", function(req, res){
	res.render('index', {title : "alarmclocks"});

});
app.get('alarm/', function (req, res) {

})
app.get("alarm/#/:val", function(req, res){
});

app.get("alarm/#/time/:val", function(req, res){
	// res.end();
});

app.get("alarm/#/time/hour/:val", function(req, res){
	res.json(data);
});

app.get("alarm/#/time/minute/:val", function(req, res){
	res.json(para);
});

app.get("alarm/output/sound/:val", function(req, res){
	// res.end();
});

app.get("alarm/output/light/:val", function(req, res){
	});// res.json(para);

app.get("alarm/#/state/:val", function(req, res){
	// res.json(para);
});
app.get("alarm/#/active/:val", function(req, res){
	// res.json(para);
});
app.get("alarm/#/repeat/:val", function(req, res){
	// res.json(para);
});


io.on("connection", function(socket){
	console.log("a user connected");

	// create copy of adjustable parameters on server
	socket.on('data', function(msg){
		para = msg;
		console.log("replaced para variable");
	});

	// create copy of font array on server
	socket.on('fonts', function(msg){
		fonts = msg;
	});
});

http.listen(8080, function(){
	console.log("listening on port 8080");
});