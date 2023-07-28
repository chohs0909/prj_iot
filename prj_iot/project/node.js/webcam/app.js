const express = require('express');
const app = express();
const path = require('path');
const SerialPort = require('serialport').SerialPort;
const sp = new SerialPort( { path:'/dev/ttyACM0', baudRate: 9600 });
const port = 3000; 
const {PythonShell} = require('python-shell');
app.get('/init',function(req,res) {

	sp.write('in\nin\n', function(err){
		if (err) {
            return console.log('Error on write: ', err.message);
        }
        console.log('init pt');
		res.writeHead(200, {'Content-Type': 'text/plain'});
		res.end('Init PT\n');
	});

}); 

app.get('/up',function(req,res)

{

	sp.write('up\nup\n', function(err){
		if (err) {

            return console.log('Error on write: ', err.message);
        }
        console.log('tilt up');

		res.writeHead(200, {'Content-Type': 'text/plain'});

		res.end('Tilt Up\n');

	});

});


app.get('/down',function(req,res)

{

	sp.write('dn\ndn\n', function(err){
		if (err) {

            return console.log('Error on write: ', err.message);
        }
        console.log('tilt down');

		res.writeHead(200, {'Content-Type': 'text/plain'});

		res.end('Tilt Down\n');

	}); 

});

app.get('/left',function(req,res)

{

	sp.write('lt\nlt\n', function(err){
		if (err) {

            return console.log('Error on write: ', err.message);
        }
        console.log('pan left');

		res.writeHead(200, {'Content-Type': 'text/plain'});

		res.end('Pan Left\n');

	}); 

});

app.get('/right',function(req,res)

{

	sp.write('rt\nrt\n', function(err){
		if (err) {

            return console.log('Error on write: ', err.message);
        }
        console.log('pan right');

		res.writeHead(200, {'Content-Type': 'text/plain'});

		res.end('Pan Right\n');

	});

});

app.get('/capture', (req, res, next)=>{
    console.log("===+");
    let options = {
        mode: 'text',
        pythonOptions: ['-u'],
        scriptPath: './',
        //args: [] //in the python script using sys.argv[1]
    };
    PythonShell.run('capture.py', options, function (err, result){
          if (err) throw err;
          console.log('result: ', result.toString());
          img_file = result.toString();
          //io.emit('img_file', img_file);
          
          res.writeHead(200, {'Content-Type': 'text/plain'});
          res.send('\n');
    });
});

 

app.use(express.static(__dirname + '/public'));

 

app.listen(port, function() {

    console.log('listening on *:' + port);

});
