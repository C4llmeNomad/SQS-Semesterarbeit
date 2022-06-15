import * as names from 'names.js';

function main() {
    startApplication("SQS-Semesterarbeit");
    clickButton(waitForObject(names.groupBoxMachineControlPushButtonConnectQPushButton));
    test.compare(waitForObjectExists(names.groupBoxMachineStatusLabelConnectionStatusQLabel).styleSheet, "border-radius: 6px; background-color: rgb(27, 193, 00)");
}
