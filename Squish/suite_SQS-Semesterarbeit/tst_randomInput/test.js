import * as names from 'names.js';

function main() {
    startApplication("SQS-Semesterarbeit");
    clickButton(waitForObject(names.groupBoxMachineControlPushButtonConnectQPushButton));
    mouseClick(waitForObject(names.groupBoxInputTextEditInputQTextEdit), 165, 101, Qt.NoModifier, Qt.LeftButton);

    type(waitForObject(names.groupBoxInputTextEditInputQTextEdit), randomString());
    clickButton(waitForObject(names.groupBoxMachineControlPushButtonStartQPushButton));
    test.compare(waitForObjectExists(names.groupBoxMachineStatusLabelRunningStatusQLabel).styleSheet, "border-radius: 6px; background-color: rgb(27, 193, 00)");
    test.compare(waitForObjectExists(names.groupBoxMachineStatusLabelErrorStatusQLabel).styleSheet, "border-radius: 6px; background-color: rgb(27, 193, 00)");
    test.compare(waitForObjectExists(names.groupBoxMachineStatusLabelConnectionStatusQLabel).styleSheet, "border-radius: 6px; background-color: rgb(27, 193, 00)"); 
    test.compare(waitForObjectExists(names.groupBoxMachineStatusLabelEStopStatusQLabel).styleSheet, "border-radius: 6px; background-color: rgb(27, 193, 00)");  
}

function randomString() {
    var value = "";
    max = 9007199254740991;
    for (i = 0; i < Math.floor(Math.random() * max) % 256; i++){
        value += Math.floor(Math.random() * max)
    }
    return value;
}