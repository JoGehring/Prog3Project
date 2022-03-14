import { Component, EventEmitter, Input, OnInit, Output } from "@angular/core";
import { List } from "src/lib/data-access/list";
import { Reminder } from "src/lib/data-access/reminder";
import { AppService } from "src/lib/feature/appService.service";


@Component({
  selector: 'list',
  templateUrl: './list.component.html',
  styleUrls: ['./list.component.scss'],
})

export class ListComponent implements OnInit{

  constructor(private appService: AppService){}
  @Input() list: List;
  @Output() deleteListEvent = new EventEmitter<number>();
  @Output() deleteReminderEvent = new EventEmitter<number>();
  @Output() showReminderEvent = new EventEmitter<number>();
  visible: boolean = false;
  newPos: number;

  ngOnInit(): void {

  }

  addReminder(){
    this.visible = true;
    let newRem: Reminder = {title: "", timestamp: this.appService.getToday(), flag: 0};
    this.newPos = this.list.reminders.push(newRem) - 1;
    newRem.position = (this.newPos == 0) ? 1 : this.list.reminders[this.newPos -1].position + 1;
    this.appService.postReminder(this.list.id, newRem).subscribe((response) => newRem.id = response.id);
    console.log(this.list.reminders[this.list.reminders.length -1]);
  }
  deleteList(id: number) {
    this.deleteListEvent.emit(this.list.id);
  }

  deleteReminder(rem: Reminder){
    this.list.reminders = this.list.reminders.filter((reminder) => reminder.id != rem.id);
    this.appService.deleteReminder(this.list.id, rem.id).subscribe();
  }

  showReminders(){
    this.visible = true;
    this.showReminderEvent.emit(this.list.id);
  }
  changeReminder(rem: Reminder){
    this.appService.putReminder(this.list.id, rem).subscribe((response) => console.log(response));
  }
}
