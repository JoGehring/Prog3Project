import { Component, EventEmitter, Input, Output } from "@angular/core";
import { List } from "src/lib/data-access/list";
import { Reminder } from "src/lib/data-access/reminder";
import { AppService } from "src/lib/feature/appService.service";


@Component({
  selector: 'flagged',
  templateUrl: './flagged.component.html',
  styleUrls: ['./flagged.component.scss'],
})

export class FlaggedComponent{

  constructor(private appService: AppService){}

  @Input() list: List;
  @Output() deleteReminderEvent = new EventEmitter<Reminder>();
  @Output() changeReminderEvent = new EventEmitter<Reminder>();

  deleteReminder(rem: Reminder){
    this.list.reminders = this.list.reminders.filter((reminder) => reminder != rem);
    this.deleteReminderEvent.emit(rem);
    this.appService.deleteReminder(rem.listId, rem.id).subscribe();
  }

  changeReminder(rem: Reminder){
    this.changeReminderEvent.emit(rem);
    this.appService.putReminder(rem.listId, rem).subscribe((response) => console.log(response));
  }
}
