import { Reminder } from "./reminder";

export interface List {
    id?: number;
    title: string;
    position?: number;
    reminders?: Reminder[];
    visible?: boolean;
}
